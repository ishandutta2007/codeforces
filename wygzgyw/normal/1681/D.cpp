// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int INF=1e9;
int n; ll t;
map<ll,int> M;
int dfs(ll x) {
	if (x>=t) return 0;
	if (M.count(x)) return M[x];
	ll y=x; int msk=0; M[x]=INF;
	while (y) {
		int v=y%10; y/=10;
		if (msk>>v&1); else {
			msk|=1<<v;
			if (v>=2) M[x]=min(M[x],dfs(x*v)+1);
		}
	}
	return M[x];
}
int main() {
	read(n); ll x; read(x);
	t=1; for (int i=1;i<n;i++) t*=10;
	int res=dfs(x);
	if (res>=INF) res=-1;
	printf("%d\n",res);
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