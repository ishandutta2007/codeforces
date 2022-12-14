#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct DSU{
	std::vector<int> p;
	DSU():p(){}
	DSU(int n):p(){reset(n);}
	void reset(int n){
		p.resize(n);
		while(n--)p[n]=n;
	}
	int root(int x){
		return p[x]!=x?p[x]=root(p[x]):x;
	}
	void join(int a,int b){ // let root(a) be the root
		p[root(b)]=root(a);
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	std::vector<int> label;
	struct Point{
		int index, x, y, a;
	};
	std::vector<Point> points(n);
	for(int i=0; i<n; ++i){
		auto& [index, x, y, a]=points[i];
		index=i;
		std::cin>>x>>y>>a;
		--a;
	}

	points.erase(std::remove_if(begin(points), end(points), [&](auto const& it){
		return it.a==it.index;
	}), points.end());

	if(points.empty()){
		std::cout<<"0\n";
		return 0;
	}
	assert(points.size()>=2);

	std::swap(points[0], *std::min_element(begin(points), end(points),
			[&](auto const& first, auto const& sec){
				return std::tie(first.x, first.y)<std::tie(sec.x, sec.y);
			}));
	std::sort(points.begin()+1, points.end(), [&](auto const& first, auto const& sec){
		int x1=first.x-points[0].x;
		int y1=first.y-points[0].y;
		int x2=sec.x-points[0].x;
		int y2=sec.y-points[0].y;
		return x1*(int64_t)y2-x2*(int64_t)y1>0;
	}); // counterclockwise around pivot

	std::vector<int> order(n);
	for(int i=0; i<points.size(); ++i)
		order[points[i].index]=i;

	DSU dsu(n); // by point **index**, not order

	for(int i=1; i<points.size(); ++i){
		auto a=points[i];
		auto b=points[order[a.a]];
		assert(b.index==a.a);

		dsu.join(a.index, b.index);
	}

	std::vector<std::array<int, 2>> operations;

	order.clear();

	for(int i=2; i<points.size(); ++i){
		auto& a=points[i-1];
		auto& b=points[i];
		if(dsu.root(a.index)!=dsu.root(b.index)){
			dsu.join(a.index, b.index);
			operations.push_back({a.index, b.index});
			std::swap(a.a, b.a);
		}
	}

	while(points[0].a!=points[0].index){
		auto& b=*std::find_if(begin(points), end(points), [&](auto const& it){
			return it.index==points[0].a;
		});
		std::swap(points[0].a, b.a);
		operations.push_back({b.index, points[0].index});
	}

	std::cout<<operations.size()<<'\n';
	for(auto [a, b]: operations)
		std::cout<<a+1<<' '<<b+1<<'\n';

}