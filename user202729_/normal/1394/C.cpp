// oh no...
// (looks correct.)
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::string s;
	std::vector<std::pair<int, int>> points;
	for(int _=0; _<number; ++_){
		std::cin>>s;
		int x=(int)std::count(begin(s), end(s), 'B'), y=(int)s.size()-x;
		points.push_back({x, y});
	};


	using Limit=std::array<int, 6>;
	auto const limits=[&](int x, int y)->Limit{
		return {{
				x,
				y,
				(x-y),
				-x,
				-y,
				-(x-y),
		}};
	};

	auto const findInstance=[&](int rad)->std::optional<std::pair<int, int>>{
		// nonzero point in the intersection of all

		if(rad<0) return {};
		Limit intersection; intersection.fill(INT_MAX);
		for(auto [x, y]: points){
			auto const cur=limits(x, y);
			for(int i=0; i<(int)intersection.size(); ++i)
				intersection[i]=std::min(intersection[i], cur[i]+rad);
		}
		assert(not points.empty());

		intersection[3]=std::min(intersection[3], 0);
		intersection[4]=std::min(intersection[4], 0);

		std::array<int, 3> xs{{intersection[0], -intersection[3], 1}};
		std::array<int, 3> ys{{intersection[1], -intersection[4], 1}};
		std::array<int, 2> diffs{{intersection[2], -intersection[5]}}; // x-y
#define TEST(x, y) \
		if(((x)!=0 or (y)!=0) and [&]{ \
			for(int i=0; i<(int)intersection.size(); ++i) \
				if(limits((x), (y))[i] > intersection[i]) \
					return false; \
			return true; \
		}()) \
			return {{(x), (y)}};
		for(auto x: xs) for(auto y: ys) TEST(x, y);
		for(auto x: xs) for(auto diff: diffs) TEST(x, x-diff);
		for(auto y: ys) for(auto diff: diffs) TEST(diff+y, y);
		return {};
	};
	auto const satisfy=[&](int rad)->bool{return !!findInstance(rad);};

	int rad=-1; // maximum rad that does not satisfy (nonzero point t in the intersection of all)
	for(int step=1;; step<<=1){
		if(not satisfy(rad+step)){
			rad+=step;
		}else{
			while(step>>=1)
				if(not satisfy(rad+step))
					rad+=step;
			break;
		}
	}
	assert(not satisfy(rad));
	++rad;
	assert(satisfy(rad));

	auto const [x, y]=*findInstance(rad);
	std::cout<<rad<<'\n';
	std::cout<<std::string(x, 'B')<<std::string(y, 'N')<<'\n';
}