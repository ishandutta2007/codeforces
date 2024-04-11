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
int n,a[200005],b[200005],wh[200005],rs=0,ans=1e9;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]),wh[b[i]]=i;
	for(int i=1;i<=n;i++) rs=max(rs,wh[i]-i+n+1);
	for(int i=1;i<=n;i++) if(wh[i]>=i) {ans=wh[i]-i;break;}
	for(int i=1;i<=n;i++) if((wh[i]<i&&ans<wh[i]-i+n+1)||(wh[i]>=i&&ans!=wh[i]-i)) {ans=1e9;break;}
	return printf("%d\n",ans==1e9?rs:ans),0;
}