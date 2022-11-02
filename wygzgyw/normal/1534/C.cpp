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
const int mod=(1e9)+7;
const int maxn=(4e5)+10;
int T,n,fa[maxn],a[maxn],q[maxn],p[maxn],b[maxn],mi[maxn];
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
void merge(int x,int y) { fa[find(x)]=find(y); }
int main() {
	//freopen("1.txt","r",stdin);
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=(mi[i-1]*2)%mod;
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),p[a[i]]=i;
		for (int i=1;i<=n;i++) read(b[i]),q[b[i]]=fa[i]=i;
		int flag=1;
		for (int i=1;i<=n;i++) if (a[i]==b[i]) { flag=0; break; }
		if (!flag) { puts("0"); continue; }
		for (int i=1;i<=n;i++) merge(p[i],q[i]);
		int cnt=0;
		for (int i=1;i<=n;i++) if (find(i)==i) cnt++;
		printf("%d\n",mi[cnt]);
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