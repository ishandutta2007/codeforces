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
const int maxm=(2e7)+10;
const int maxn=(4e6)+10;
int T,n;
int lsh[200010],N;
struct node {
	int op,l,r,id;
} d[200010];
bool cmp(node A,node B) { return (A.l==B.l?A.r<B.r:A.l<B.l); }
int fa[maxn];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
set<pair<int,int> > s[2];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); N=0;
		for (int i=1;i<=n;i++) {
			read(d[i].op),read(d[i].l),read(d[i].r),d[i].id=i;
			fa[i]=i;
		}
		sort(d+1,d+n+1,cmp);
		s[0].clear(),s[1].clear();
		for (int i=1;i<=n;i++) {
			for (int j=0;j<2;j++) while ((int)s[j].size()&&(*s[j].begin()).first<d[i].l) s[j].erase(s[j].begin());
			int op=d[i].op^1;
			while ((int)s[op].size()) {
				pair<int,int> A=*s[op].begin();
				fa[find(i)]=find(A.second);
				if ((int)s[op].size()>1) s[op].erase(A); else break;
			}
			s[op^1].insert(MP(d[i].r,i));
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans+=find(i)==i;
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