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
const int maxn=(5e5)+10;
int T,n;
vector<pair<int,int> > g[maxn];
set<pair<int,int> > s;
int ans[maxn];
int main() {
	read(T);
	while (T--) {
		read(n); int l,r,x;
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=n;i++) {
			read(x);
			int l=i/(x+1)+1,r=(x==0?n:i/x);
			g[l].push_back(MP(r,i));
		}
		s.clear();
		for (int i=1;i<=n;i++) {
			for (pair<int,int> &A : g[i]) s.insert(A);
			set<pair<int,int> > :: iterator it=s.begin();
			ans[(*it).second]=i;
			s.erase(it);
		}
		for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
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