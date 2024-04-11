#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int INF = 1e9;
const int N = 2505;
const double pi = acos(-1);
mt19937 rng(time(0));

struct Point{
	LL x,y;
	void in(){scanf("%lld%lld",&x,&y);}
	bool operator<(Point r){
		bool up1 = y>0 || y==0 && x>0, up2 = r.y>0 || r.y==0 && r.x>0;
		return (up1&&!up2) || (up1||!up2) && (x*r.y>y*r.x);
	}
	Point operator-(Point r){return {x-r.x,y-r.y};}
}a[N], b[N];
int n, m;

LL C(int x, int y){ LL res = 1; rep(i,1,y) res = res * (x+1-i) / i;	return res;}
bool cmp(Point x, Point y){return x.x*y.y>x.y*y.x || x.x==y.x && x.y==y.y;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	rep(i,1,n) a[i].in();
	
	LL ans = 0;
	rep(i,1,n){
		memcpy(b,a,sizeof b), swap(b[i], b[n]);
		rep(j,1,n-1) b[j] = b[j] - a[i];
		sort(b+1, b+n);
		
		int r = 1;
		rep(j,1,n-1){
			if(b[j].y>0 || b[j].y==0 && b[j].x>0){
				while(r<n && cmp(b[j],b[r])) ++r;
				ans += C(r-j-1,3);
			}else{
				if(r>=j) r = 1;
				while(r<j && cmp(b[j],b[r])) ++r;
				ans += C(n+r-j-2,3);
			}
		}
	}
	ans = C(n,5) * 5 - ans;
	printf("%lld\n",ans);
	return 0;
}