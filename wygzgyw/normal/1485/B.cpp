#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,q,l,r;
ll a[maxn],s[maxn],k,ans;
ll S(int l,int r) { return s[r]-s[l-1]; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q),read(k);
	for (int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
	while (q--) {
		read(l),read(r);
		if (l==r) printf("%lld\n",k-1);
		else {
			ans=S(l+1,r)+k+1;
			ans-=S(l,r-1);
			ans-=(r-l+1)*2;
			printf("%lld\n",ans);
		}
	}
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