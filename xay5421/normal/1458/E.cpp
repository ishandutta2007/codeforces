// author: xay5421
// created: Sun Dec 20 11:13:25 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,INF=0X3F3F3F3F;
int n,m;
set<pair<int,int> >sxy;
set<int>sx,sy;
struct cmp{
	bool operator()(const pair<int,int>&k1,const pair<int,int>&k2)const{
		return k1.Y^k2.Y?k1.Y<k2.Y:k1.X<k2.X;
	}
};
set<pair<int,int>,cmp>syx;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		sx.insert(x),sy.insert(y);
		sxy.insert(make_pair(x,y));
		syx.insert(make_pair(x,y));
	}
	set<pair<int,int> >lose;
	{
		int x=0,y=0;
		lose.insert(make_pair(0,0));
		while(1){
			{
				if(sxy.find(make_pair(x,y))!=sxy.end()){
					++x,++y;
					continue;
				}
			}
			{
				auto it=sxy.upper_bound(make_pair(x,y));
				if(it!=sxy.begin()&&prev(it)->X==x&&prev(it)->Y<=y){
					++x;
					continue;
				}
			}
			{
				auto it=syx.upper_bound(make_pair(x,y));
				if(it!=syx.begin()&&prev(it)->Y==y&&prev(it)->X<=x){
					++y;
					continue;
				}
			}
			lose.insert(make_pair(x,y));
			{
				int dt=INF;
				{
					auto it=sx.upper_bound(x);
					if(it!=sx.end()){
						dt=min(dt,*it-x);
					}
				}
				{
					auto it=sy.upper_bound(y);
					if(it!=sy.end()){
						dt=min(dt,*it-y);
					}
				}
				if(dt==INF)break;
				x+=dt,y+=dt;
			}
		}
	}
	auto sol=[&](int x,int y){
		if(sxy.find(make_pair(x,y))!=sxy.end())return 0;
		{
			auto it=sxy.upper_bound(make_pair(x,y));
			//D("x=%d y=%d prevX=%d prevY=%d\n",x,y,prev(it)->X,prev(it)->Y);
			if(it!=sxy.begin()&&prev(it)->X==x&&prev(it)->Y<=y){
				return 1;
			}
		}
		{
			auto it=syx.upper_bound(make_pair(x,y));
			if(it!=syx.begin()&&prev(it)->Y==y&&prev(it)->X<=x){
				return 1;
			}
		}
		auto it=lose.upper_bound(make_pair(x,INF));
		assert(it!=lose.begin());
		--it;
		if(x-it->X!=y-it->Y)return 1;
		return 0;
	};
	rep(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		puts(sol(x,y)?"WIN":"LOSE");
	}
	return 0;
}