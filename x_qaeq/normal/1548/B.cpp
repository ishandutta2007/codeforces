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
int n;ll a[200005],st[200005][25],lg[200005];
inline ll qry(int l,int r) {int g=lg[r-l+1];return __gcd(st[l][g],st[r-(1<<g)+1][g]);}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=n;i>=1;i--) a[i]=abs(a[i-1]-a[i]);
	lg[0]=-1;for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1,st[i][0]=a[i];
	for(int j=1;j<=20;j++) for(int i=1;i+(1<<(j-1))<=n;i++) st[i][j]=__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	int rs=1;for(int l=1,r=1;l<=n;l++)
	{
		r=max(l,r);while(r<n&&qry(l+1,r+1)>1) r++;
		rs=max(rs,r-l+1);
	}
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}