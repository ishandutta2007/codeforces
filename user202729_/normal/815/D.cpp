#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,xx,yy,zz;std::cin>>n>>xx>>yy>>zz;
	struct point{int x,y,z;};
	std::vector<point> points;points.reserve(3*n+1);
	// scan z decreasing (zz -> 0)
	// at each slice the set of removed blocks contains (0,0,0).
	for(int _=n;_--;){
		int x,y,z;
		std::cin>>x>>y>>z;
		points.push_back({x,y,zz});
		points.push_back({xx,y,z});
		points.push_back({x,yy,z});
	}
	std::sort(begin(points),end(points),[](point a,point b){
			return a.z>b.z;
			});
	points.push_back({xx,yy,0});

	std::map<int,int> rem; // x -> y
	rem.emplace(0,yy);
	rem.emplace(xx,0);
	int64_t area=xx*(int64_t)yy;

	auto const add=[&](int x,int y){
		auto iter=rem.lower_bound(x);
		if(iter->second>=y)
			return;
		if(iter->first>x)
			iter=rem.insert(iter,{x,iter->second});
		while(true){
			auto pre=std::prev(iter);
			if(y>=pre->second){
				area-=(pre->second-iter->second)*int64_t(iter->first-pre->first);
				iter->second=pre->second;
				rem.erase(pre);
				if(y==iter->second)
					break;
			}else{
				area-=(y-iter->second)*int64_t(iter->first-pre->first);
				iter->second=y;
				break;
			}
		}
	};

	int lastz=zz;
	int64_t ans=0;
	for(point p:points){
		if(p.z!=lastz){
			ans+=area*(lastz-p.z);
			lastz=p.z;
		}
		add(p.x,p.y);
	}

	std::cout<<ans<<'\n';
}