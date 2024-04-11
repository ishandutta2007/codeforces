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
const int P=998244353;int n,ans,fc[200005],dg[200005];
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),dg[x]++,dg[y]++;
	fc[0]=ans=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	for(int i=1;i<=n;i++) ans=1ll*ans*fc[dg[i]]%P;
	return printf("%lld\n",1ll*ans*n%P),0;
}