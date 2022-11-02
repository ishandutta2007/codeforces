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
const int maxn=(2.5e5)+10;
int n,a[maxn],id[maxn];
int f[maxn],g[maxn],h[maxn],ans;
int d[maxn],tot;
bool cmp(int x,int y) {
	if (a[x]==a[y]) return x>y;
	return a[x]<a[y];
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
namespace Seg {
int tr[maxn];
void init() { for (int i=1;i<=n;i++) tr[i]=0; }
void add(int x,int y) {
	for (;x<=n;x+=x&(-x)) update(tr[x],y);
}
int query(int x) {
	int res=0; for (;x;x-=x&(-x)) update(res,tr[x]); return res;
}
int query(int l,int r) {
	return (query(r)-query(l-1)+mod)%mod;
}
};
int pos[maxn],T;
bool CMP(int x,int y) { return a[x]<a[y]; }
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),id[i]=i;
		sort(id+1,id+n+1,cmp);
		for (int i=1;i<=n;i++) a[id[i]]=i,h[i]=0;
		//for (int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
		Seg::init();
		for (int i=1;i<=n;i++) f[i]=Seg::query(a[i])+1,Seg::add(a[i],f[i]);
		Seg::init();
		for (int i=n;i>=1;i--) g[i]=Seg::query(a[i],n)+1,Seg::add(a[i],g[i]);
		tot=0; int mx=0;
		for (int i=n;i>=1;i--) {
			mx=max(mx,a[i]); if (mx==a[i]) d[++tot]=i;
		}
		d[tot+1]=n+1;
		for (int i=1;i<=n;i++) {
			pos[i]=lower_bound(d+1,d+tot+1,i,CMP)-d;
		}
		Seg::init();
		for (int i=n;i>=1;i--) {
			pos[i]=d[pos[i]];
			if (pos[i]<=i) h[i]=1;
			else h[i]=Seg::query(a[i],a[pos[i]])+1,Seg::add(a[i],h[i]);
		}
		ans=0;
		for (int i=1;i<=n;i++) update(ans,(ll)f[i]*g[i]%mod),update(ans,mod-(ll)f[i]*h[i]%mod);
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