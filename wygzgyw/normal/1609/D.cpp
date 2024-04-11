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
const int maxn=1010;
int n,m,ans,ad,fa[maxn],sz[maxn],all;
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
multiset<int> s,t; multiset<int>::iterator it;
int main() {
	read(n),read(m); for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1,s.insert(1); int x,y;
	while (m--) {
		read(x),read(y); ans=0;
		x=find(x),y=find(y);
		if (x!=y) fa[x]=y,s.erase(s.find(sz[x])),s.erase(s.find(sz[y])),sz[y]+=sz[x],s.insert(sz[y]);
		else ad++;
		t=s; it=t.end(); it--; ans+=(*it)-1;
		t.erase(it);
		for (int i=1;i<=ad;i++) {
			if (t.empty()) break;
			it=t.end(); it--; ans+=(*it); t.erase(it);
		}
		printf("%d\n",ans);
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