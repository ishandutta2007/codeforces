#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

template<class T>
struct Point{
	T x,y;
	int ind;
	Point operator+(Point a)const{
		return {x+a.x,y+a.y};
	}
	Point operator-(Point a)const{
		return {x-a.x,y-a.y};
	}
	bool operator==(Point a)const{
		return x==a.x&&y==a.y;
	}
	T dot(Point a)const{
		return x*a.x+y*a.y;
	}
	T cross(Point a)const{
		return x*a.y-y*a.x;
	}
};

using pt=Point<int>;
using ptl=Point<int64_t>;

bool ccw(pt a,pt b){
	return a.cross(b)>0;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<pt> p(n);
	for(int ind=0;ind<n;++ind){
		pt& a=p[ind];
		std::cin>>a.x>>a.y;
		a.ind=ind+1;
	}
	auto iter=std::partition(begin(p),end(p),[](pt a){
			return a.y>0||(a.y==0&&a.x>0);
			});
	std::sort(begin(p),iter,ccw);
	std::sort(iter,end(p),ccw);

	ptl mina{-1,0};
	int ans1=-1,ans2=-1;

	for(int i=0;i<n;++i){
		pt a=p[i];
		pt b=p[i+1==n?0:i+1];
		ptl angle{a.dot(b),a.cross(b),-1};
		if(angle.y<0)angle.y=-angle.y;

		if(angle.cross(mina)>=0){
			mina=angle;
			ans1=a.ind;
			ans2=b.ind;
		}
	}
	std::cout<<ans1<<' '<<ans2<<'\n';
}