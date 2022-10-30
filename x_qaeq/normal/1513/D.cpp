//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,wp,a[200005],fa[200005];pair<int,int>p[200005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
inline void solve()
{
	read(n),read(wp);ll rs=0;int cnt=0;for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) read(a[i]),p[i]=make_pair(a[i],i);
	sort(p+1,p+n+1);for(int i=1,wh;i<=n;i++) if(p[i].first<wp)
	{
		int qwq=p[i].first;
		wh=p[i].second;while(wh>1&&getf(wh-1)^getf(wh)&&a[wh-1]%qwq==0) mrg(wh-1,wh),rs+=p[i].first,cnt++,wh--;
		wh=p[i].second;while(wh<n&&getf(wh+1)^getf(wh)&&a[wh+1]%qwq==0) mrg(wh+1,wh),rs+=p[i].first,cnt++,wh++;
	}
	printf("%lld\n",rs+1ll*(n-1-cnt)*wp);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}