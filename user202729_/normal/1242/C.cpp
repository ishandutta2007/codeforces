#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<unordered_map>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nbox;std::cin>>nbox;

	struct item{
		int ind,box;
	};
	std::unordered_map<int,item> boxes_by_val; // val -> {ind,box}

	std::vector<int64_t> boxsum(nbox);
	int64_t sumall{};

	int nitem=0;
	for(int box=0;box<nbox;++box){
		int n;std::cin>>n;
		for(int z=0;z<n;++z){
			int valz;std::cin>>valz;
			auto [_,success]=boxes_by_val.insert({valz,{nitem++,box}}); assert(success);
			boxsum[box]+=valz;
			sumall+=valz;
		}
	}

	if(sumall%nbox){
		std::cout<<"No\n";
		return 0;
	}
	int64_t avg=sumall/nbox;

	std::vector<std::pair<int,item>> boxes_by_ind(nitem); // ind -> auto
	for(auto x:boxes_by_val)
		boxes_by_ind[x.second.ind]=x;


	std::vector<int> nxt(nitem); // nxt[i]: if item index i is removed from its box
	// which item should be added to that box? or -1
	for(int i=nitem;i--;){
		assert(boxes_by_ind[i].second.ind ==i);
		int box=boxes_by_ind[i].second.box;
		int vali=boxes_by_ind[i].first;

		int64_t valnxt=avg-(boxsum[box]-vali);
		if(valnxt!=(int)valnxt)
			nxt[i]=-1;
		else{
			auto iter=boxes_by_val.find((int)valnxt);
			if(iter==end(boxes_by_val))
				nxt[i]=-1;
			else
				nxt[i]=iter->second.ind;
		}
	}

	std::vector<int> startitem(1<<nbox,-1); // mask -> possible start item

	for(int i=nitem;i--;){ // complexity: nitem * nbox
		int mask=0;
		int k=i;
		for(int z=nbox+1;z--;){
			if(mask&(1<<boxes_by_ind[k].second.box)){
				if(k==i)
					// found good cycle. must have length < nbox
					startitem[mask]=i;
				goto nexti;
			}
			mask|=1<<boxes_by_ind[k].second.box;
			k=nxt[k];
			if(k<0)
				goto nexti;
		}

		// no cycle found that contains i
nexti:;
	}

	std::vector<int> dp(1<<nbox); // mask -> possible submask int startitem or 0
	for(int mask=1<<nbox;mask--;)
		if(startitem[mask]>=0)
			dp[mask]=mask;

	for(int mask=1;mask<(1<<nbox);++mask){
		if(dp[mask])
			continue;

		for(int subm=mask;subm;subm=(subm-1)&mask){
			if(startitem[subm]>=0&&dp[mask^subm]){
				dp[mask]=subm;
				continue;
			}
		}
	}

	if(dp.back()){
		std::cout<<"Yes\n";
		int mask=(1<<nbox)-1;
		std::vector<std::pair<int,int>> ans(nbox); // {val, new box}
		while(mask){
			int subm=dp[mask];
			assert(subm);

			int i=startitem[subm];
			int j=i;
			do{
				int k=nxt[j];
				ans[boxes_by_ind[k].second.box]={boxes_by_ind[k].first,boxes_by_ind[j].second.box};
				j=k;
			}while(j!=i);

			mask^=subm;
		}
		for(auto [vali,nbox]:ans)
			std::cout<<vali<<' '<<nbox+1<<'\n';
	}else{
		std::cout<<"No\n";
	}
}