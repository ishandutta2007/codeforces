#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

struct BIT{
	std::vector<int64_t> d;
	BIT(int n):d(n){}
	void add(unsigned i,int64_t a){
		for(;i<d.size();i+=~i&-~i)
			d[i]+=a;
	}
	int64_t sumprefix(int i)const{
		int64_t ans=0;
		for(;i>=0;i-=~i&-~i)
			ans+=d[i];
		return ans;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	struct pt{
		int x,y;
	};
	int n;std::cin>>n;
	std::vector<pt> points(n);
	for(pt& p:points)std::cin>>p.x>>p.y;


	// coordinate compression
	int n_yval;
	{
		std::sort(begin(points),end(points),[](pt a,pt b){return a.y<b.y;});
		int lasty=points[0].y;points[0].y=0;
		for(auto iter=++begin(points);iter!=end(points);++iter)
			if(iter->y==lasty)
				iter->y=iter[-1].y;
			else{
				lasty=iter->y;
				iter->y=iter[-1].y+1;
			}
		n_yval=points.back().y+1;
	}
	{
		std::stable_sort(begin(points),end(points),[](pt a,pt b){return a.x<b.x;});
		int lastx=points[0].x;points[0].x=0;
		for(auto iter=++begin(points);iter!=end(points);++iter)
			if(iter->x==lastx)
				iter->x=iter[-1].x;
			else{
				lastx=iter->x;
				iter->x=iter[-1].x+1;
			}
	}

	// now points is sorted by x, or y if x are equal
	BIT t(n_yval),nx(n_yval);
	// t[y] = number of rect with min y = y, min x edge is tight
	// nx.sumprefix(y) = number of distinct x values with y >= y

	int64_t ans=0;
	for(int i=0;i<n;++i){
		pt p=points[i];
		pt pre=i ? points[i-1] : pt{};
		if(i!=0&&pre.x==p.x){
			// nx.sumprefix(y) += 1 for pre.y < y <= p.y
			nx.add(pre.y+1,1);
			if(p.y+1<n_yval)
				nx.add(p.y+1,-1);
		}else{
			// nx.sumprefix(y) += 1 for y<=p.y
			nx.add(0,1);
			if(p.y+1<n_yval)
				nx.add(p.y+1,-1);
		}

		auto const z=nx.sumprefix(p.y);
		t.add(p.y,z);

		// set z to 0
		nx.add(p.y,-z);
		if(p.y+1<n_yval)
			nx.add(p.y+1,z);

		if(i+1==n||p.x!=points[i+1].x)
			ans+=t.sumprefix(p.y);
	}
	std::cout<<ans<<'\n';
}

// 3  1 1 2 3 3 2