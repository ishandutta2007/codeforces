#ifndef LOCAL
#define NDEBUG
#endif
#include<numeric>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<algorithm>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	struct poly{
		int ind,nside;
	};
	std::vector<poly> ps(n);
	for(int i=0;i<n;++i){
		ps[i].ind =i;
		std::cin>>ps[i].nside;
	}
	std::sort(begin(ps),end(ps),[](poly a,poly b){return a.nside<b.nside;}); // is this necessary?

	std::vector<std::pair<int,int>> dp(n);
	dp[0]={ps[0].nside,ps[0].nside};
	for(int i=1;i<n;++i){
		auto& out=dp[i];
		auto const [a,b]=dp[i-1];
		int const c=ps[i].nside;
		if(c<a)
			out={a-c+2,b+c-2};
		else if(c>b)
			out={c-b+2,c+b-2};
		else
			out={3+not ((a^c)&1),c+b-2};
	}

	// min number of vertices = dp.back().first

	std::vector<int> g(n); // g: chosen number of vertices
	g.back()=dp.back().first;
	for(int i=n-1;i;--i){
		auto const [a,b]=dp[i-1];
		int const c=ps[i].nside;

		int const d=g[i];
		int& od=g[i-1];

		assert(od==0);
		for(int od1:{a,b,c,c-1,c+1}){
			// check if od1 & c can make d
			if(!(a<=od1 and od1<=b and (od1&1)==(a&1))){
				// invalid od1
				continue;
			}
			int mind=c==od1?4:std::abs(c-od1)+2;
			int maxd=c+od1-2;
			assert((maxd&1)==(mind&1));
			assert((d&1)==(mind&1));

			if(mind<=d and d<=maxd){
				// ok
				od =od1;
				break;
			}
		}
		assert(od>0);
	}

	std::vector<std::vector<int>> ans(n);

	assert(g[0]==ps[0].nside);
	int nnode=g[0];
	std::vector<int> cur(nnode-1);
	int const root=0;
	std::iota(begin(cur),end(cur),1);

	ans[ps[0].ind]=cur;
	ans[ps[0].ind].push_back(root);

	for(int i=1;i<n;++i){
		int oldg=g[i-1];
		assert(oldg==(int)cur.size()+1);
		int nside=ps[i].nside;
		int newg=g[i];

		int n_shared_side=(oldg+nside-newg)/2;
		int n_shared_node=n_shared_side+1; // inc. root
		assert(n_shared_node>=2);
		assert(n_shared_node<=nside);

		std::vector<int> newp;newp.reserve(nside);
		if(n_shared_node ==3&&nside==3){
			assert(cur.size()>=3);
			newp.assign(cur.end()-3,cur.end());
			cur.erase(cur.end()-2);
		}else{
			for(int z=n_shared_node-2;z--;){
				newp.push_back(cur.back());
				cur.pop_back();
			}
			newp.push_back(cur.back());

			for(int z=nside-n_shared_node;z--;){
				cur.push_back(nnode);
				newp.push_back(nnode);
				++nnode;
			}
			newp.push_back(root);
		}

		assert(newp.size()==nside);
		ans[ps[i].ind]=newp;
	}
	
	std::cout<<nnode<<'\n';
	for(auto x:ans){
		for(auto y:x)
			std::cout<<y+1<<' ';
		std::cout<<'\n';
	}
}