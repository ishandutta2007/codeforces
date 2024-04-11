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
const int maxn=2010;
int n,mod;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int a[maxn];
int pre[maxn];
bool vis[maxn];
int all;
void insert(int x) {
	vis[x]=1;
	if (x>1&&vis[x-1]) all++;
	if (x<n&&vis[x+1]) all++;
}
int dp[maxn][maxn][3];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int jc[maxn],C[maxn][maxn],ans[maxn];
int main() {
	read(n),read(mod);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<n;i++) {
		pre[i+1]=pre[i];
		if (a[i]+1==a[i+1]) pre[i+1]++;
	}
	jc[0]=1; for (int i=1;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod;
	
	dp[0][0][0]=dp[1][0][0]=dp[1][0][2]=1;
	for (int op=0;op<=2;op++) {
		for (int i=2;i<=n;i++) {
			for (int j=0;j<i;j++) {
				if (j==0) {
					dp[i][j][0]=jc[i];
					dp[i][j][1]=(jc[i]-jc[i-1]+mod)%mod;
					dp[i][j][2]=jc[i-1];
					continue;
				}
				dp[i][j][0]=(dp[i][j-1][0]-dp[i-1][j-1][0]+mod)%mod;
				dp[i][j][1]=(dp[i][j-1][1]-dp[i-1][j-1][1]+mod)%mod;
				dp[i][j][2]=(dp[i][j-1][2]-dp[i-1][j-1][2]+mod)%mod;
			}
		}
	}
	
	for (int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	
	
	for (int i=n;i>=1;i--) {
		insert(a[i]);
		int nsp[3][2];
		memset(nsp,0,sizeof(nsp));
		for (int x=1;x<a[i];x++) if (vis[x]) {
			int base=pre[i-1]+(i>1&&x==a[i-1]+1),cnt=all,flag=0;
			if (x>1&&vis[x-1]) cnt--;
			if (x<n&&vis[x+1]) flag=1,cnt--;
			
			if (base==pre[i-1]) {
				nsp[all-cnt][flag]++; continue;
			}
			
			for (int v=0;v<=cnt;v++) {
				if (flag) {
					update(ans[base+v],(ll)C[cnt][v]*dp[n-i-v][cnt-v][1]%mod);
					update(ans[base+v+1],(ll)C[cnt][v]*dp[n-i-v][cnt-v][2]%mod);
				} else {
					update(ans[base+v],(ll)C[cnt][v]*dp[n-i-v][cnt-v][0]%mod);
				}
			}
		}
		int base=pre[i-1];
		for (int cnt=max(0,all-2);cnt<=all;cnt++)
		for (int flag=0;flag<=1;flag++) if (nsp[all-cnt][flag]) {
			for (int v=0;v<=cnt;v++) {
				if (flag) {
					update(ans[base+v],(ll)C[cnt][v]*dp[n-i-v][cnt-v][1]%mod*nsp[all-cnt][flag]%mod);
					update(ans[base+v+1],(ll)C[cnt][v]*dp[n-i-v][cnt-v][2]%mod*nsp[all-cnt][flag]%mod);
				} else {
					update(ans[base+v],(ll)C[cnt][v]*dp[n-i-v][cnt-v][0]%mod*nsp[all-cnt][flag]%mod);
				}
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[n-i]); puts("");
	return 0;
}