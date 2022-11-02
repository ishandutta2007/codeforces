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
const int maxn=110;
int T,n;
struct node { int a,b,id; } d[maxn];
bool cmp(node A,node B) {
	if (A.a==B.a) return A.b<B.b;
	return A.a<B.a;
}
int rk[maxn],flag,p[maxn];
vector<pair<int,int> > ans;
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(d[i].a),d[i].id=i;
		for (int i=1;i<=n;i++) read(d[i].b);
		sort(d+1,d+n+1,cmp);
		for (int i=1;i<=n;i++) rk[d[i].id]=i;
		flag=1;
		for (int i=1;i<n;i++) flag&=(d[i].b<=d[i+1].b);
		//for (int i=1;i<=n;i++) printf("%d ",rk[i]); puts("");
		if (!flag) { puts("-1"); continue; }
		ans.clear();
		for (int i=1;i<=n;i++) p[i]=i;
		while (1) {
			flag=1;
			for (int i=1;i<n;i++) flag&=(rk[p[i]]<rk[p[i+1]]);
			if (flag) break;
			for (int i=1;i<n;i++) if (rk[p[i]]>rk[p[i+1]]) ans.push_back(MP(i,i+1)),swap(p[i],p[i+1]);
		}
		printf("%d\n",(int)ans.size());
		for (auto [x,y] : ans) printf("%d %d\n",x,y);
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