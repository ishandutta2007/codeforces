#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct pt{ int64_t x,y; };
auto& operator>>(std::istream& str,pt& p){ return str>>p.x>>p.y; }
int64_t dist(pt a,pt b){ return std::abs(a.x-b.x)+std::abs(a.y-b.y); }

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	pt datastart,mul,offset,start;
	int64_t time;
	std::cin>>datastart>>mul>>offset>>start>>time;

	std::vector<pt> ps{datastart};
	while(true){
		auto [x,y]=ps.back();
		if(x>=10000000000000000LL or y>=10000000000000000LL) break;
		assert(mul.x<=100 and mul.y<=100);
		ps.push_back(pt{x*mul.x+offset.x, y*mul.y+offset.y});
	}

	int ncollected=0;
	for(unsigned i=0;i<ps.size();++i){
		auto last=start;
		int64_t time_cur=0;
		int ncollected_cur=0;
		for(unsigned j=i+1;j--;){
			time_cur+=dist(last,ps[j]);
			++ncollected_cur;
			if(time_cur>time) break; else ncollected=std::max(ncollected,ncollected_cur);
			last=ps[j];
		}
		for(unsigned j=i+1;j<ps.size();++j){
			time_cur+=dist(last,ps[j]);
			++ncollected_cur;
			if(time_cur>time) break; else ncollected=std::max(ncollected,ncollected_cur);
			last=ps[j];
		}
	}
	std::cout<<ncollected<<'\n';
}