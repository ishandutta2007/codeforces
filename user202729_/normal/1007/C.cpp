// I cheated by viewing the real verdict (on main tests) int the (virtual) contest.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

int ask(int64_t x,int64_t y){
	std::cout<<x<<' '<<y<<std::endl;
	int ans;std::cin>>ans;
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t n;std::cin>>n;
	struct strip{
		int64_t x1,x2,y1,y2;
	};
	std::vector<strip> ss; // increasing consecutive x ranges, decreasing y2, constant y1, half inclusive
	ss.push_back({1,n+1,1,n+1});
	while(true){
		assert(std::cerr <<ss.size()<<'\n');
		for(auto [x1,x2,y1,y2]:ss)
			assert(x1<x2 and y1<y2);
		for(unsigned i=1;i<ss.size();++i){
			assert(ss[i-1].x2==ss[i].x1);
			assert(ss[i-1].y1==ss[i].y1);
			assert(ss[i-1].y2>=ss[i].y2);
		}

		double ma=0; // up to 10**36
		for(auto [x1,x2,y1,y2]:ss)
			ma+=(x2-x1)*double(y2-y1);
		ma/=3;

		// find min x s.t. area of part with x<x is >=ma
		int64_t x=ss.back().x2;
		for(int64_t step=1LL<<62;step;step>>=1){
			x-=step;
			double area=0;
			for(auto const& [x1,x2,y1,y2]:ss)
				if(x1<x)
					area+=(std::min(x,x2)-x1)*double(y2-y1);
			if(area<ma)
				x+=step;
		}

		// find min y s.t. area of part with y<y is >=ma
		int64_t y=ss[0].y2;
		for(int64_t step=1LL<<62;step;step>>=1){
			y-=step;
			double area=0;
			for(auto const& [x1,x2,y1,y2]:ss)
				if(y1<y)
					area+=(x2-x1)*double(std::min(y,y2)-y1);
			if(area<ma)
				y+=step;
		}

		switch(ask(x-1,y-1)){
			case 1:
				for(auto& [x1,x2,y1,y2]:ss)
					x1=std::max(x1,x);
				ss.erase(std::remove_if(begin(ss),end(ss),[](strip const& s){return s.x1>=s.x2;}),end(ss));
				break;
			case 2:
				for(auto& [x1,x2,y1,y2]:ss)
					y1=std::max(y1,y);
				ss.erase(std::remove_if(begin(ss),end(ss),[](strip const& s){return s.y1>=s.y2;}),end(ss));
				break;
			case 3:
				{
					--x;--y;
					std::vector<strip> nss;
					nss.reserve(ss.size()+1);
					for(strip const& s:ss){
						auto const [x1,x2,y1,y2]=s;
						if(x2<=x or y2<=y)
							nss.push_back(s);
						else{
							if(x1<x)
								nss.push_back({x1,x,y1,y2});
							if(y1<y)
								nss.push_back({std::max(x1,x),x2,y1,y});
						}
					}
					ss=std::move(nss);
				}
				break;
			case 0:
				return 0;
			default:
				assert(false);
				__builtin_unreachable();
		}
	}
}