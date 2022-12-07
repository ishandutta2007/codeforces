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

void solve(){
	int n,x,y,v1,v2,v3,v4,v,ans;
	scanf("%d%d%d",&n,&x,&y);
	v1=x-1; v2=y-1; v3=n-x; v4=n-y; ans=n;
	v=min(1,min(v3,v4)); ans-=v; v3-=(v3!=0); v4-=(v4!=0);
	v=min(v1,v4); ans-=v; v1-=v; v4-=v;
	v=min(v2,v3); ans-=v; v2-=v; v3-=v;
	v=min(v3,v4); ans-=v; v3-=v; v4-=v;
	printf("%d ",ans);
	v1=x-1; v2=y-1; v3=n-x; v4=n-y; ans=1;
	v=min(v1,v4); ans+=v; v1-=v; v4-=v;
	v=min(v2,v3); ans+=v; v2-=v; v3-=v;
	v=min(v1,v2); ans+=v; v1-=v; v2-=v;
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
2
5 1 3
6 3 4
*/