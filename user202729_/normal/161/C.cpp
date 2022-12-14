// 14
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int l1,r1,l2,r2;
	std::cin>>l1>>r1>>l2>>r2;
	struct segment{ int l,r; };
	std::vector<segment> s{{l1-1,r1}},t{{l2-1,r2}};
	int out=0;
	for(int i=30;i--;){
		auto const N=(1<<i)-1;
		// all endpoints are no more than 2 * N + 1
		for(auto [l1,r1]:s) for(auto [l2,r2]:t)
			out=std::max(out,std::min(r1,r2)-std::max(l1,l2));

		for(auto px:{&s,&t}){
			auto& x=*px;
			std::vector<segment> x1;
			for(auto [l,r]:x){
				assert(l<r);
				if(l<=N and r>N){
					x1.push_back({l,N});
					x1.push_back({0,r-N-1});
				}else if(r<=N){
					x1.push_back({l,r});
				}else{
					assert(l>N);
					x1.push_back({l-N-1,r-N-1});
				}
			}

			x1.erase(std::remove_if(begin(x1),end(x1),[&](segment s){
						assert(0<=s.l and s.l<=s.r and s.r<=N);
						return s.l==s.r;
						}),end(x1));
			std::sort(begin(x1),end(x1),[](segment a,segment b){
					return a.r-a.l > b.r-b.l;
					});

			x.clear();
			for(auto [l,r]:x1){
				if(std::none_of(begin(x),end(x),[&](segment pre){return pre.l<=l and r<=pre.r;}))
					x.push_back({l,r});
			}
		}
	}

	if(out==0 and not s.empty() and not t.empty()){
		assert(s[0].l==0 and s[0].r==1);
		assert(t[0].l==0 and t[0].r==1);
		out=1;
	}
	std::cout<<out<<'\n';
}