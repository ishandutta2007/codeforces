#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
int m,x[1010],n;
ll ans,tmp;
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
//void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	//freopen("1.txt","r",stdin);
	read(m);
	for (int i=1;i<=m;i++) read(x[i]),n+=x[i];
	if (m==1) { puts("0"); return 0; }
	sort(x+1,x+m+1); x[++m]=n;
	int j=0; ll s=1,t=1;
	int X=n*2,Y=n+1;
	for (int a=1;a<=n;++a) {
		X--,Y--;
		s=s*X%mod,t=t*Y%mod;
		while (j<m&&x[j+1]==a) {
			++j;
			tmp=s*ksm(t,mod-2)%mod-1;
			if (j!=m) ans+=tmp;
			else ans+=mod-tmp;
			if (ans>=mod) ans-=mod;
		}
	}
	ans=ans*n%mod*ksm(n-1,mod-2)%mod;
	ans=(mod-2*ans%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/