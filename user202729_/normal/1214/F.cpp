#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ncoord,n;std::cin>>ncoord>>n;
	std::vector<int> a(n),b(n);

	struct ev{
		int pos,deg,ind;
	};
	std::vector<ev> evs;evs.reserve(n*2+1);

	for(int i=0;i<n;++i){int x;std::cin>>x;evs.push_back({x,1,i});}
	for(int i=0;i<n;++i){int x;std::cin>>x;evs.push_back({x,-1,i});}

	std::sort(begin(evs),end(evs),[](ev a,ev b){return a.pos<b.pos;});
	evs.push_back({evs[0].pos+ncoord,0,-1}); // placeholder

	int deg=n; // so deg cannot drop below 0
	std::vector<int> cnt(2*n+1); // deg -> number of segments
	for(unsigned i=0;i+1<evs.size();++i){
		deg+=evs[i].deg;
		int len=evs[i+1].pos-evs[i].pos;
		if(len)
			cnt[deg]+=len;
	}
	assert(deg==n);

	auto iter=begin(cnt);
	{
		int x=ncoord/2;
		while(x>=*iter){
			x-=*iter;++iter;
		}
	}

	for(unsigned i=0;i+1<evs.size();++i){
		deg+=evs[i].deg;
		int len=evs[i+1].pos-evs[i].pos;
		if(len&&deg==iter-begin(cnt)){
			if(i+1!=evs.size())
				std::rotate(begin(evs),begin(evs)+i+1,--end(evs));
			evs.pop_back();

			std::vector<int> ans(n);
			std::vector<ev> st;st.reserve(n);
			int64_t totlen=0;
			for(auto e:evs)
				if(st.empty()||e.deg==st.back().deg)
					st.push_back(e);
				else{
					assert(e.deg==-st.back().deg);
					auto f=st.back();st.pop_back();
					if(e.deg==1)
						std::swap(e,f);

					assert(e.deg==-1); // candidate
					assert(f.deg==1); // vacancy
					ans[f.ind]=e.ind;
					int d =std::abs(e.pos-f.pos);
					totlen+=std::min(d,ncoord -d);
				}

			std::cout<<totlen<<'\n';
			for(auto x:ans)std::cout<<x+1<<' ';
			std::cout<<'\n';
			return 0;
		}
	}
	assert(false);
}