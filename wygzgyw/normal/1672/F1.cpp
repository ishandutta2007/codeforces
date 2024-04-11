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
int T,n,a[maxn],cnt[maxn];
vector<int> g[maxn];
bool cmp(int x,int y) { return cnt[x]>cnt[y]; }
int b[maxn],c[maxn],ans[maxn],tot,id[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) cnt[i]=0,g[i].clear();
		for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++,g[a[i]].push_back(i);
		for (int i=1;i<=n;i++) id[i]=i;
		sort(id+1,id+n+1,cmp); tot=0;
		for (int i=1;i<=n;i++) {
			for (int &j : g[i]) b[++tot]=j;
		}
		int mx=cnt[id[1]];
		for (int i=1,j=mx+1;i<=n;i++,j++) {
			if (j>n) j=1;
			c[i]=b[j];
		}
		//for (int i=1;i<=n;i++) printf("%d ",b[i]); puts("");
		//for (int i=1;i<=n;i++) printf("%d ",c[i]); puts("");
		for (int i=1;i<=n;i++) ans[b[i]]=c[i];
		for (int i=1;i<=n;i++) printf("%d ",a[ans[i]]); puts("");
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