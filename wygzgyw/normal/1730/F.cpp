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
const int INF=0x7f7f7f7f;
int n,p[5010];
int dp[5010][1<<8];
void chkmin(int &x,int y) { if (x>y) x=y; }
int pre[5010],P[5010][5010],k,cnt;
int bit[1<<8],d[10000],w[1<<8];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	for (int i=1;i<=n;i++) {
		int x; read(x); p[x]=i;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) P[i][j]=P[i][j-1]+(p[i]<p[j]);
	}
	memset(dp,INF,sizeof(dp));
	for (int t=0;t<(1<<k);t++) {
		int cnt=0;
		for (int i=2;i<=k+1;i++) if ((t>>(i-2)&1)&&p[i]>p[1]) cnt++;
		dp[1][t]=cnt;
	}
	int ans=INF;
	for (int i=1;i<=n;i++) for (int t=0;t<(1<<k);t++) if (dp[i][t]!=INF) {
		int fd=0;
		for (int j=i+1;j<=i+k+1&&j<=n;j++) if (!(t>>(j-i-1)&1)) { fd=j; break; }
		if (!fd) { chkmin(ans,dp[i][t]); continue; }
		int msk=0;
		for (int j=fd+1;j<=i+k+1&&j<=n;j++) if (t>>(j-i-1)&1) msk|=1<<(j-fd-1);
		for (int j=fd;j<=fd+k&&j<=n;j++) {
			pre[j]=P[j][i-1];
			for (int v=i;v<=i+k;v++) if (i==v||(t>>(v-i-1)&1)) pre[j]+=(p[j]<p[v]); 
		}
		int tot=0;
		for (int s1=(1<<k)-1-msk;;s1=(s1-1)&((1<<k)-1-msk)) { d[++tot]=s1; if (!s1) break; }
		for (int j=fd+1;j<=fd+k&&j<=n;j++) w[1<<(j-fd-1)]=pre[j]+(p[fd]<p[j]);
		for (int ii=tot;ii>=1;ii--) {
			int s1=d[ii];
			if (s1) bit[s1]=bit[s1-(s1&(-s1))]+w[s1&(-s1)];
			int s=s1+msk,tmp=pre[fd]+bit[s1];
			//for (int j=fd+1;j<=fd+k&&j<=n;j++) if (s1>>(j-fd-1)&1) tmp+=pre[j]+(p[fd]<p[j]);
			chkmin(dp[fd][s],dp[i][t]+tmp);
			//cnt++;
			//if (!s1) break;
		}
	}
	//cerr<<cnt<<endl;
	printf("%d\n",ans);
	return 0;
}