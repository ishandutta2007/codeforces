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
const int mod=998244353;
const int maxn=(3e5)+10;
int n,m,k,vis[maxn],cnt[maxn],f[maxn],a[maxn];
int ban[maxn],pre[maxn],nxt[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	read(k),read(n),read(m);
	for (int i=1;i<=k;i++) {
		int len; read(len);
		for (int j=1;j<=len;j++) read(a[j]);
		for (int j=1;j<len;j++) {
			if (nxt[a[j]]&&nxt[a[j]]!=a[j+1]) ban[nxt[a[j]]]=ban[a[j]]=1;
			nxt[a[j]]=a[j+1];
		}
		for (int j=2;j<=len;j++) {
			if (pre[a[j]]&&pre[a[j]]!=a[j-1]) ban[pre[a[j]]]=ban[a[j]]=1;
			pre[a[j]]=a[j-1];
		}
	}
	for (int i=1;i<=m;i++) if (!pre[i]) {
		int len=0,x=i,flag=0;
		while (x&&!vis[x]) len++,vis[x]=1,flag|=ban[x],x=nxt[x];
		if (!flag&&!x) cnt[len]++;
	}
	vector<int> V;
	for (int i=1;i<=n;i++) if (cnt[i]) V.push_back(i);
	f[0]=1;
	for (int i=1;i<=n;i++) for (int j : V) if (i>=j) update(f[i],(ll)cnt[j]*f[i-j]%mod);
	printf("%d\n",f[n]);
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