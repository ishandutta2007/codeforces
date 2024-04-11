//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n,a[2005],sm[2005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),sm[i]=sm[i-1]^a[i];
	if(sm[n]==0) return puts("YES"),void();//1-i,i+1-j,j+1-n
	for(int i=1;i<n;i++) for(int j=i+1;j<n;j++) if(sm[j]==0&&(sm[i]^sm[n])==0) return puts("YES"),void();
	puts("NO");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}