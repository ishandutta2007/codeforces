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
const int INF=1e9;
const int maxn=310;
int n,f[maxn][maxn],w[maxn][maxn];
int a[maxn],d[maxn],A[maxn][maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
vector<int> g[maxn];
int q,id[maxn],D[maxn],rk[maxn];
int iv[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
void init() {
	for (int i=1;i<=n;i++) {
		A[i][i]=i;
		for (int &j : g[i]) A[i][j]=j;
	}
	for (int i=1;i<=n;i++) {
		f[i][i]=1;
		for (int j=i;j>=1;j--) {
			if (j!=i) f[i][j]=mod-(ll)f[i][j]*iv[i-j]%mod;
			for (int k=1;k<j;k++) update(f[i][k],mod-(ll)A[k][j]*f[i][j]%mod);
		}
	}
	for (int i=1;i<=n;i++) {
		w[i][i]=1;
		for (int j=i;j>=1;j--) {
			for (int k=1;k<j;k++) update(w[i][k],mod-(ll)f[j][k]*w[i][j]%mod);
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) update(f[i][j],f[i][j-1]);
}
bool cmp(int x,int y) { return d[x]<d[y]; }
int tr[maxn][maxn],val[maxn][maxn];
void add(int *tr,int x,int delta) {
	for (;x<=n;x+=x&(-x)) update(tr[x],delta);
}
int query(int *tr,int x) {
	int res=0; for (;x;x-=x&(-x)) update(res,tr[x]); return res;
}
void build() {
	for (int i=n;i>=1;i--) if (a[i]>0) d[i]=0; else { d[i]=INF; for (int &j : g[i]) d[i]=min(d[i],d[j]+1); }
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++) rk[id[i]]=i,D[i]=d[id[i]];
	for (int j=1;j<=n;j++) for (int i=1;i<=n;i++) val[j][i]=(ll)ksm(iv[j],d[i])%mod*w[i][j]%mod,tr[j][i]=0;
	for (int j=1;j<=n;j++) for (int i=1;i<=n;i++) {
		add(tr[j],rk[i],(ll)(a[i]+mod)*val[j][i]%mod);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	iv[0]=iv[1]=1; for (int i=2;i<=n;i++) iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
	for (int i=1;i<=n;i++) {
		int x,y; read(x); if (x) { while (x--) read(y),g[i].push_back(y); }
	}
	init();
	build();
	read(q);
	while (q--) {
		int op,x,y,k;
		read(op);
		if (op==1) {
			read(k),read(x),read(y); int ans=0;
			int pos=lower_bound(D+1,D+n+1,k)-D-1;
			for (int j=1;j<=n;j++) {
				update(ans,(ll)ksm(j,k)*(f[j][y]-f[j][x-1]+mod)%mod*query(tr[j],pos)%mod);
			}
			for (int j=x;j<=y;j++) if (d[j]>=k) update(ans,(a[j]+mod)%mod);
			printf("%d\n",ans);
		} else {
			read(x),read(y);
			int pre=a[x];
			a[x]+=y;
			if (pre<=0&&a[x]>0) build();
			else {
				for (int j=1;j<=n;j++) {
					add(tr[j],rk[x],(ll)y*val[j][x]%mod);
				}
			}
		}
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