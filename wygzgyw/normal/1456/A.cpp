#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
const int maxn=(2e5)+10;
int T,n,p,k,x,y,c[maxn],a[maxn];
char s[maxn];
ll ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(p),read(k);
		memset(c,0,sizeof(c));
		scanf("%s",s+1);
		read(x),read(y);
		for (int i=1;i<=n;i++) a[i]=s[i]-'0';
		for (int i=n;i>=1;i--) {
			c[i]=c[i+k]+1-a[i];
		}
		ans=INF;
		for (int i=0;i<=n-p;i++) {
			ans=min(ans,(ll)i*y+(ll)c[i+p]*x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/