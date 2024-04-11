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
int T,n,m;
pair<int,int> E[maxn];
int fa[maxn];
int f[maxn];
int find(int x) { if (f[x]==x) return x; return f[x]=find(f[x]); }
int ans[maxn];
struct Query {
	int l,r,id,L,R,mid;
	friend bool operator < (Query A,Query B) { return A.mid<B.mid; }
};
vector<Query> Q,Q2; int q;
vector<int> g[maxn];
void upd(int z) {
	if (z>1&&fa[z-1]==fa[z]) f[find(z)]=find(z-1);
	if (z<n&&fa[z+1]==fa[z]) f[find(z+1)]=find(z);
}
void add(int x,int y) {
	if (fa[x]==fa[y]) return;
	x=fa[x],y=fa[y];
	if ((int)g[x].size()<(int)g[y].size()) swap(x,y);
	for (int &z : g[y]) g[x].push_back(z),fa[z]=x,upd(z);
}
int main() {
	read(T);
	while (T--) {
		read(n),read(m),read(q);
		for (int i=1;i<=m;i++) read(E[i].first),read(E[i].second);
		int l,r; Q.clear();
		for (int i=1;i<=q;i++) {
			read(l),read(r); if (l==r) ans[i]=0; else Q.push_back((Query){l,r,i,1,m,0});
		}
		while (!Q.empty()) {
			for (int i=0;i<Q.size();i++) Q[i].mid=((Q[i].L+Q[i].R)>>1);//,printf("%d %d\n",A.mid,A.R);
			sort(Q.begin(),Q.end());
			int pos=1; for (int i=1;i<=n;i++) fa[i]=i,g[i]={i},f[i]=i;
			Q2.clear();
			for (int i=0;i<Q.size();i++) {
				Query A=Q[i];
				while (pos<=Q[i].mid) {
					add(E[pos].first,E[pos].second);
					pos++;
				}
				if (find(Q[i].r)<=Q[i].l) {
					if (A.L<A.mid) A.R=A.mid-1,Q2.push_back(A); ans[A.id]=A.mid;
				} else {
					if (A.mid<A.R) A.L=A.mid+1,Q2.push_back(A);
				}
			}
			Q.swap(Q2);
		}
		for (int i=1;i<=q;i++) printf("%d ",ans[i]); puts("");
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