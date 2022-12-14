// >.<

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, maxL;std::cin>>number>>maxL;
	std::vector<int> l(number);for(auto & it: l) { std::cin>>it; --it; }
	std::vector<int> candidateCost(number);for(auto & it: candidateCost) std::cin>>it;
	std::vector<int> valueProfit(number+maxL);for(auto & it: valueProfit) std::cin>>it;

	assert(bool(std::cin));
	{
		char c; std::cin>>c;
		assert(not std::cin);
	}

	std::vector<std::vector<int>> f(number, std::vector<int>(number+1, INT_MIN));
	int result=0;

	std::vector<std::vector<int>> up(maxL, std::vector<int>(number+1, INT_MIN));

	for(int i=number-1; i>=0; --i){
		f[i][1]=std::max(f[i][1], 0);

		for(int t=0;t<(int)f[i].size();++t) {
			f[i][t]=std::max(f[i][t], up[l[i]][t]);
		}

		std::vector<int> up1(maxL, INT_MIN); // up1[a] updates to up[b][1], b>=a

		for(int t=0;t<(int)f[i].size();++t) {
			auto const cur=f[i][t];
			if(cur==INT_MIN) continue;

			std::array<int, 14> value;
			{
				int next=cur-candidateCost[i];

				for(int x=l[i];x<l[i]+(int)value.size();++x) {
					value[x-l[i]]=next;
					if(t>>(x-l[i]))
						next+=(t>>(x-l[i]))*valueProfit[x];
				}
			}

#if 1
			auto const split=std::min(maxL, l[i]+(int)value.size());
			for(int lj=l[i];lj<split;++lj) {
				auto const delta=lj-l[i];
				//if(1+(t>>delta) < (int)up[lj].size()) { // ???
					int& target= up[lj][1+(t>>delta)];
					target=std::max(target, value[delta]);
				//}
			}

			/*
			for(auto lj=split; lj<maxL;++lj){
				int& target= up[lj][1];
				target=std::max(target, value.back());
			}
			*/

			if(split<maxL){
				int& target= up1[split];
				target=std::max(target, value.back());
			}

#else
			for(int j=i; j--;) if(l[j]>=l[i]){
				auto const delta=l[j]-l[i];
				int& target=f[j][1+(t>>delta)];
				target=std::max(target, value[std::min(delta,(int)value.size()-1)]);
			}
#endif

			{ // total O(n^2 log n) only
				int next=cur-candidateCost[i];
				for(int x=l[i];;++x) {
					if((t>>(x-l[i]))==0) break;
					next+=(t>>(x-l[i]))*valueProfit[x];
				}

				result=std::max(result, next);
			}
		}

		for(int index=0;index+1<maxL;++index) 
			up1[index+1]=std::max(up1[index+1], up1[index]);
		for(int index=0;index<maxL;++index) 
			up[index][1]=std::max(up[index][1], up1[index]);

	}
	std::cout<<result<<'\n';
}