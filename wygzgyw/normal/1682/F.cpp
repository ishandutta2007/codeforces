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
const int maxn=(2e5)+10;
int n,q,a[maxn];
ll s[maxn];
vector<pair<int,int> > g[maxn];
bool cmp(int x,int y) { return s[x]<s[y]; }
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
namespace T1 {
int tr[maxn];
void clear() { memset(tr,0,sizeof(tr)); }
void add(int x,int y) {
	for (;x<=n;x+=x&(-x)) update(tr[x],y);
}
int query(int x) {
	int res=0; for (;x;x-=x&(-x)) update(res,tr[x]); return res;
}
int query(int x,int y) { return (query(y)-query(x-1)+mod)%mod; }
};
int ans[maxn],id[maxn];
namespace T2 {
int tr[maxn];
void clear() { memset(tr,0,sizeof(tr)); }
void add(int x,int y) {
	for (;x<=n;x+=x&(-x)) update(tr[x],y);
}
int query(int x) {
	int res=0; for (;x;x-=x&(-x)) update(res,tr[x]); return res;
}
int query(int x,int y) { return (query(y)-query(x-1)+mod)%mod; }
};
int main() {
	read(n),read(q);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) a[i]=a[i+1]-a[i];
	for (int i=1;i<=n;i++) read(s[i]),s[i]+=s[i-1];
	for (int i=1;i<=q;i++) {
		int x,y; read(x),read(y);
		g[x-1].push_back(MP(y,i));
	}
	for (int i=0;i<=n;i++) id[i]=i;
	sort(id,id+n+1,cmp);
	for (int i=1;i<=n;i++) s[i]=(s[i]%mod+mod)%mod;
	for (int i=n;i>=0;i--) {
		int l=id[i];
		for (auto [r,id] : g[l]) update(ans[id],(T1::query(l+1,r-1)+(ll)T2::query(l+1,r-1)*s[l]%mod)%mod);
		if (l&&l<n) {
			T1::add(l,(ll)a[l]*s[l]%mod);
			T2::add(l,mod-a[l]);
		}
	}
	T1::clear(),T2::clear();
	for (int i=0;i<=n;i++) {
		int l=id[i];
		for (auto [r,id] : g[l]) update(ans[id],(T1::query(l+1,r-1)+(ll)T2::query(l+1,r-1)*s[l]%mod)%mod);
		if (l&&l<n) {
			T1::add(l,mod-((ll)a[l]*s[l]%mod));
			T2::add(l,a[l]);
		}
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
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