//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,a[1000005];
inline char chk(int w) {if(w<0) return 0;else {int x=sqrt(w);return x*x==w||(x+1)*(x+1)==w;}}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int rs=-1e9;for(int i=1;i<=n;i++) if(!chk(a[i])) rs=max(rs,a[i]);
	return printf("%d\n",rs),0;
}