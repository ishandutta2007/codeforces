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
int n,L[maxn];
int tot,d[maxn],a[maxn],b[maxn];
bool cmp(int x,int y) { return b[x]>b[y]; }
int tr[maxn],f[maxn],ans;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void add(int x,int delta) {
	for (;x<=n*2;x+=x&(-x)) update(tr[x],delta);
}
int query(int x) {
	int res=0; for (;x;x-=x&(-x)) update(res,tr[x]); return res;
}
int query(int l,int r) { return (query(r)-query(l)+mod)%mod; }
int main() {
	read(n);
	int l,r;
	for (int i=1;i<=n;i++) {
		read(a[i]),read(b[i]),L[b[i]]=a[i];
	}
	read(tot);
	for (int i=1;i<=tot;i++) read(d[i]);
	sort(d+1,d+tot+1,cmp);
	for (int i=1;i<=n*2;i++) if (L[i]) {
		f[i]=query(L[i],i)+1;
		add(L[i],f[i]);
	}
	l=0,r=n*2;
	for (int I=1,i;I<=tot;I++) {
		i=d[I];
		if (a[i]<=l) continue;
		ans++;
		while (r>=b[i]) {
			if (L[r]) add(L[r],mod-f[r]);
			r--;
		}
		update(ans,query(l,r));
		l=a[i];
	}
	printf("%d\n",ans);
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