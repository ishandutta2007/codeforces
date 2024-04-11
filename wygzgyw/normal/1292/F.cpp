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
const int maxn=110;
int n,a[maxn],fa[maxn],in[maxn];
vector<int> V[maxn];
int ans,from[maxn],f[1<<15],g[1<<15][70],C[70][70];
int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	read(n); for (int i=1;i<=n;i++) read(a[i]),fa[i]=i;
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (a[j]%a[i]==0) {
		fa[find(i)]=find(j); in[j]++;
	}
	for (int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for (int i=1;i<=n;i++) V[find(i)].push_back(i);
	int all=0,ans=1;
	for (int i=1;i<=n;i++) if ((int)V[i].size()>1) {
		vector<int> S;
		for (int &v : V[i]) if (!in[v]) S.push_back(v);
		int sz=(int)S.size(),cnt=0;
		memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
		for (int &v : V[i]) if (in[v]) {
			cnt++; from[v]=0;
			for (int j=0;j<S.size();j++) if (a[v]%a[S[j]]==0) from[v]|=1<<j;
			f[from[v]]++;
		}
		for (int i=0;i<sz;i++) for (int t=0;t<(1<<sz);t++) if (t>>i&1) f[t]+=f[t^(1<<i)];
		g[0][0]=1;
		for (int j=0;j<(1<<sz);j++) for (int k=0;k<=cnt;k++) if (g[j][k]) {
			if (k<f[j]) update(g[j][k+1],(ll)g[j][k]*(f[j]-k)%mod);
			for (int &v : V[i]) if (in[v]&&((from[v]&j)!=0||j==0)&&(from[v]&j)!=from[v])
				update(g[j|from[v]][k+1],g[j][k]);
		}
		ans=(ll)ans*g[(1<<sz)-1][cnt]*C[all+cnt-1][cnt-1]%mod;
		all+=cnt-1;
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