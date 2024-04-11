#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
const int maxn=(1e5)+10;
int T,n,c1,c2;
ll c[maxn],tmp,ans,sumodd,sumeven,mnodd,mneven;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(c[i]);
		ans=INF;
		sumodd=sumeven=0,mnodd=mneven=INF;
		c1=c2=0;
		for (int i=1;i<=n;i++) {
			if (i&1) sumodd+=c[i],c1++,mnodd=min(mnodd,c[i]);
			else sumeven+=c[i],c2++,mneven=min(mneven,c[i]);
			if (i==1) continue;
			
			tmp=(sumodd-mnodd)+mnodd*(n-(c1-1));
			tmp+=(sumeven-mneven)+mneven*(n-(c2-1));
			ans=min(ans,tmp);
			
		}
		printf("%lld\n",ans);
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