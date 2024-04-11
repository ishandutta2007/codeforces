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
const int maxn=45;
const int maxm=(1e7)+10;
int n;
int jc[maxn],f[maxn],F[maxn][maxn];
int p[maxn];
int w[maxn],W[1<<20],tot;
int dp[maxm];
namespace Map {
const int mod=(1e7)+9;
int head[mod],tot,to[maxm],nxt[maxm];
int query(int x) {
	for (int i=head[x%mod];i;i=nxt[i]) if (to[i]==x) return i;
	tot++; nxt[tot]=head[x%mod]; head[x%mod]=tot; to[tot]=x;
	return tot;
}
};
int Hash(int t,int x,int y,int lst) {
	int res=lst+x*(n+1)+y*(n+1)*(n+1)+t*(n+1)*(n+1)*(n+1);
	return Map::query(res);
}
bool vis[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int C[maxn][maxn],a[maxn][maxn],h[maxn];
int calc(int t,int i,int j,int A,int B) {
	int res=1;
	for (int v=0;v<tot;v++) if (t>>v&1) res=(ll)res*(a[A][w[v+1]]-a[A-B][w[v+1]]+mod)%mod;
	for (int v=0;v<i;v++) res=(ll)res*(a[A][1]-a[A-B][1]+mod)%mod;
	for (int v=0;v<j;v++) res=(ll)res*(a[A][2]-a[A-B][2]+mod)%mod;
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	jc[0]=1; for (int i=1;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod;
	for (int i=0;i<n;i++) f[i]=(ll)jc[i]*jc[n-i-1]%mod;
	for (int i=1;i<=n;i++) read(p[i]);
	int t1=0,t2=0;
	for (int i=1;i<=n;i++) if (!vis[i]) {
		int cnt=0,x=i;
		while (!vis[x]) vis[x]=1,x=p[x],cnt++;
		if (cnt==1) t1++; else if (cnt==2) t2++; else w[++tot]=cnt;
	}
	for (int i=0;i<=n;i++) {
		F[i][0]=1;
		for (int j=1;j<=n;j++) F[i][j]=(ll)F[i][j-1]*f[i]%mod;
	}
	for (int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for (int i=0;i<tot;i++) W[1<<i]=w[i+1];
	for (int t=1;t<(1<<tot);t++) W[t]=W[t-(t&(-t))]+W[t&(-t)];
	
	for (int t=0;t<(1<<tot);t++)
	for (int i=0;i<=t1;i++) for (int j=0;j<=t2;j++) {
		if (W[t]+i+j*2==0) continue;
	//	printf(" %d %d %lld\n",W[t]+i+j*2,Hash(t,i,j,W[t]+i+j*2),(ll)F[0][i+j*2+W[t]]*C[t1][i]%mod*C[t2][j]%mod);
		dp[Hash(t,i,j,W[t]+i+j*2)]=(ll)F[0][i+j*2+W[t]]*C[t1][i]%mod*C[t2][j]%mod;
	}

	for (int i=0;i<=n;i++) {
		for (int x=0;x<=n;x++) update(h[i],(ll)f[x]*C[i][x]%mod);
		//printf("%d\n",h[i]);
		a[i][0]=1;
		for (int x=1;x<=n;x++) a[i][x]=(ll)a[i][x-1]*h[i]%mod;
	}
	//printf("%d %d\n",t1,t2);
	//for (int i=0;i<tot;i++) printf("%d ",w[i+1]); puts("");
	
	for (int t=0;t<(1<<tot);t++) for (int i=0;i<=t1;i++) for (int j=0;j<=t2;j++) for (int lst=0;lst<=n;lst++) {
		int now=dp[Hash(t,i,j,lst)];
		if (!now) continue;
		//printf("%d %d %d %d\n",t,i,j,lst);
		for (int i2=0;i2+i<=t1;i2++) for (int j2=0;j2+j<=t2;j2++) {
			int msk=(1<<tot)-1-t;
			for (int s=msk;;s=(s-1)&msk) {
				if (!i2&&!j2&&!s) break;
				update(dp[Hash(t|s,i2+i,j2+j,W[s]+i2+j2*2)],(ll)
					calc(s,i2,j2,W[t]+i+j*2,lst)*C[t1-i][i2]%mod*C[t2-j][j2]%mod*now%mod);
				if (!s) break;
			}
		}
	}
	
	int ans=0;
	for (int lst=0;lst<=n;lst++) {
		//printf("%d %d\n",lst,Hash((1<<tot)-1,t1,t2,lst));
		update(ans,dp[Hash((1<<tot)-1,t1,t2,lst)]);
	}
	printf("%d\n",ans);
	
	return 0;
}