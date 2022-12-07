#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int h,c,t,ans;
#define double long double
pll v;
int cmp(pll x,pll y){
	x.fi-=1ll*x.se*t;
	y.fi-=1ll*y.se*t;
	if (x.fi<0) x.fi*=-1;
	if (y.fi<0) y.fi*=-1;
	ll del=1ll*x.fi*y.se-1ll*y.fi*x.se;
	if (!del) return 0;
	return del<0?-1:1;
}
void solve(){
	scanf("%d%d%d",&h,&c,&t);
	pll v(1e9,1),m(h+c,2);
	if (cmp(m,v)==-1) v=m,ans=2;
	int l=0,r=1e6;
	while (l<=r){
		int mid=(l+r)/2;
		pll m(1ll*h*mid+h+1ll*c*mid,2ll*mid+1);
		int key=cmp(m,v);
		if (key==-1||(key==0&&mid*2+1<=ans))
			ans=2*mid+1,v=m;
		1ll*m.se*t<m.fi?l=mid+1:r=mid-1;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1
999977 17 499998

*/