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
int Ca,n,m,a[200055];const int P=1e9+7;
inline void init()
{//0
	for(int i=0;i<=9;i++) a[i]=1;
	for(int i=10;i<=200050;i++) a[i]=(a[i-9]+a[i-10])%P;
}
inline void solve()
{
	read(n),read(m);int res=0;
	while(n) (res+=a[m+n%10])%=P,n/=10;
	printf("%d\n",res);
}
int main() {for(read(Ca),init();Ca--;) solve();return 0;}