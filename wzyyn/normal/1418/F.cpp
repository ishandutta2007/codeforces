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
int n,m,vis[200005];
ll l,r;
vector<int> ans[200005];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%lld%lld",&l,&r);
	int V=max(n,m);
	for (int p1=1;p1*p1<=V;p1++)
		for (int p2=p1+1;p2*p2<=V;p2++)
			for (int x=V/p2;x;x--) if (!ans[p1*x].size()){
				ll dv=1ll*p1*p2*x,y=(l+dv-1)/dv;
				if (1ll*p2*y>m) break;
				if (1ll*p1*p2*x*y>r) continue;
				if (1ll*p2*x<=n&&1ll*p2*y<=m)
					ans[p1*x]=vector<int>{p1*x,p2*x,p2*y,p1*y};
			}
	for (int x=1;x*x<=V;x++)
		for (int y=1;y*y<=V;y++)
			for (int p1=V/max(x,y)-1;p1;p1--) if (!ans[p1*x].size()){
				ll dv=1ll*p1*x*y;
				ll p2=(l+dv-1)/dv;
				if (1ll*p2*x>n||1ll*p2*y>m) break;
				p2=max(p2,p1+1ll);
				if (1ll*p1*p2*x*y>r) continue;
				if (1ll*p2*x<=n&&1ll*p2*y<=m)
					ans[p1*x]=vector<int>{p1*x,p2*x,p2*y,p1*y};
			}
	For(i,1,n)
		if (!ans[i].size()) puts("-1");
		else printf("%d %d %d %d\n",ans[i][0],ans[i][2],ans[i][1],ans[i][3]);
}
/*
p1x p2x
p1y p2y

x 
*/