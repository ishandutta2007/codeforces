#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
int T,n;
ll u,v,ans,a[110];
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n); read(u), read(v);
		for (int i=1;i<=n;i++) read(a[i]);
		ans=INF;
		for (int i=1;i<n;i++) if (abs(a[i]-a[i+1])>=2) { ans=0; break; }
		if (ans==INF) {
			for (int i=1;i<n;i++) ans=min(ans,v*abs(abs(a[i+1]-a[i])-2));
			for (int i=1;i<=n;i++) {
				if (i>1) {
					if (a[i]==a[i-1]) ans=min(ans,u+v);
					else ans=min(ans,u);
				}
				if (i<n) {
					if (a[i]==a[i+1]) ans=min(ans,u+v);
					else ans=min(ans,u);
				}
			}
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