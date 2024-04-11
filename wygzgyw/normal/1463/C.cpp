#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int INF=(1e9)+10;
const int maxn=(1e5)+10;
int T,n,x[maxn],t[maxn];
int ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		int p=0,q=0,now; ans=0;
		for (int i=1;i<=n;i++) read(t[i]),read(x[i]);
		for (int i=1;i<=n;i++) {
			if (p==q) q=x[i];
			if (i==n||t[i+1]-t[i]>=abs(p-q)) now=q;
			else {
				if (p<q) now=p+t[i+1]-t[i];
				else now=p-(t[i+1]-t[i]);
			}
			if ((ll)(x[i]-p)*(x[i]-now)<=0) ans++;
			p=now;
		}
		printf("%d\n",ans);
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