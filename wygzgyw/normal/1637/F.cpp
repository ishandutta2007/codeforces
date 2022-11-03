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
const int maxn=(2e5)+10;
int n,h[maxn];
int deg[maxn];
set<pair<int,int> > s;
vector<int> g[maxn];
int st[maxn],del[maxn];
ll ans;
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(h[i]),st[i]=h[i];
	int x,y;
	for (int i=1;i<n;i++) read(x),read(y),g[x].push_back(y),g[y].push_back(x),deg[x]++,deg[y]++;
	sort(st+1,st+n+1);
	for (int i=1;i<=n;i++) if (deg[i]<=1) s.insert(MP(h[i],i)),del[i]=1;
	for (int i=1;i<=n;i++) {
		while (s.size()&&(*s.begin()).first<st[i]) {
			int x=(*s.begin()).second;
			s.erase(s.begin());
			for (int &y : g[x]) if (!del[y]) {
				deg[y]--;
				if (deg[y]<=1) s.insert(MP(h[y],y)),del[y]=1;
			}
		}
		ans+=(ll)max(2,(int)s.size())*(st[i]-st[i-1]);
	}
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