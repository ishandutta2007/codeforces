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
const int maxn=(2e5)+10;
int T,n;
set<int> s;
int in[maxn],cnt;
vector<int> g[maxn];
int main() {
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) in[i]=0,g[i].clear();
		for (int i=1;i<=n;i++) {
			int x,y; read(x);
			for (int j=1;j<=x;j++) read(y),g[y].push_back(i),in[i]++;
		}
		s.clear();
		int ans=0; cnt=0;
		for (int i=1;i<=n;i++) if (in[i]==0) s.insert(i);
		while ((int)s.size()) {
			ans++;
			int x=0;
			while (1) {
				set<int>::iterator it=s.lower_bound(x);
				if (it==s.end()) break;
				x=*it;
				cnt++;
				s.erase(it);
				for (int &y : g[x]) {
					in[y]--;
					if (!in[y]) s.insert(y);
				}
			}
		}
		if (cnt!=n) puts("-1");
		else printf("%d\n",ans);
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