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
const int maxn=110;
int n,d[maxn][maxn],x[maxn],y[maxn],tot;
int ans;
pair<int,int> p[maxn];
int BB[maxn];
vector<int> V;
bool ok[maxn][maxn];
bool check(int a,int b,int c) {
	return d[a][b]==d[b][c]&&d[a][b]==d[c][a]&&ok[a][b]&&ok[a][c]&&ok[b][c];
}
bool check(int a,int b,int c,int d) {
	return check(a,b,c)&&check(b,c,d)&&check(a,b,d)&&check(a,c,d)&&BB[a]==3&&BB[b]==3&&BB[c]==3;
}
namespace BF {
int col[maxn];
void dfs(int u) {
	if (u>n) {
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) for (int k=1;k<=n;k++)
			if (i!=j&&j!=k&&i!=k) {
				if (col[i]==col[j]&&col[j]==col[k]) {
					if (d[i][j]==d[j][k]&&d[i][j]==d[k][i]); else return;
				} else if (col[i]==col[j]) {
					if (d[i][j]<d[j][k]&&d[i][j]<d[k][i]); else return;
				}
			}
		ans++;
		return;
	}
	for (col[u]=1;col[u]<=n;col[u]++) dfs(u+1);
}
void solve() {
	dfs(1);
	printf("%d\n",ans);
	exit(0);
}
};
int f[maxn],g[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int jc[maxn],iv[maxn],ivjc[maxn];
void init(){jc[0]=jc[1]=iv[0]=iv[1]=ivjc[0]=ivjc[1]=1;for(int i=2;i<maxn;++i)jc[i]=(ll)jc[i-1]*i%mod,iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod,ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;}
inline int C(int n,int m){return n<m||m<0?0:(ll)jc[n]*ivjc[m]%mod*ivjc[n-m]%mod;}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) d[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	if (n==2) { puts("4"); return 0; }
	if (n<=5) BF::solve();
	for (int i=1;i<=n;i++) {
		tot=0;
		for (int j=1;j<=n;j++) if (i!=j) p[++tot]=MP(d[i][j],j);
		sort(p+1,p+tot+1);
		int cnt=0;
		for (int j=1;j<=tot;j++) if (p[j].first==p[1].first) cnt++,ok[i][p[j].second]=1;
		BB[i]=cnt;
	}
	for (int i=1;i<=n;i++) {
		tot=0;
		for (int j=1;j<=n;j++) if (i!=j) p[++tot]=MP(d[i][j],j);
		sort(p+1,p+tot+1);
		int cnt=0;
		for (int j=1;j<=tot;j++) if (p[j].first==p[1].first) cnt++;
		if (cnt==1) {
			int x=p[1].second;
			if (x<i&&BB[x]==1&&ok[x][i]) V.push_back(2);
		}
		if (cnt==2) {
			if (i<p[1].second&&i<p[2].second&&BB[p[1].second]==2&&BB[p[2].second]==2&&check(i,p[1].second,p[2].second)) V.push_back(3);
		}
		if (cnt==3) {
			if (i<p[1].second&&i<p[2].second&&i<p[3].second&&check(i,p[1].second,p[2].second,p[3].second)) V.push_back(4);
		}
	}
	//for (int &x : V) printf("%d ",x); puts("");
	init();
	int sum=0;
	for (int &x : V) sum+=x;
	f[n-sum]=1;
	for (int &x : V) {
		memset(g,0,sizeof(g));
		for (int i=0;i<=n;i++) if (f[i]) update(g[i+1],f[i]),update(g[i+x],f[i]);
		for (int i=0;i<=n;i++) f[i]=g[i];
	}
	for (int i=1;i<=n;i++) update(ans,(ll)C(n,i)*jc[i]%mod*f[i]%mod);
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