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
const int maxn=(2e5)+10;
int n;
int dp[maxn][2][2];
char s[2][maxn];
void chkmin(int &x,int y) { if (x>y) x=y; }
int ans;
int main() {
	read(n);
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	memset(dp,INF,sizeof(dp));
	if (s[1][1]=='1') dp[1][1][1]=0,dp[1][0][0]=1;
	else dp[1][0][0]=0;
	for (int i=1;i<n;i++) {
		for (int j=0;j<=1;j++) for (int k=0;k<=1;k++) if (dp[i][j][k]>=0) {
			int d[2];
			for (d[0]=0;d[0]<=1;d[0]++) for (d[1]=0;d[1]<=1;d[1]++) {
				if (s[0][i+1]=='0'&&d[0]) break;
				if (s[1][i+1]=='0'&&d[1]) break;
				int tmp=dp[i][j][k]+(s[0][i+1]-'0'!=d[0])+(s[1][i+1]-'0'!=d[1]);
				if (!d[0]&&!d[1]) { chkmin(dp[i+1][j][0],tmp); continue; }
				if (k&&d[j^1]) continue;
				int j2; if (d[0]&&d[1]) j2=j^1; else j2=(d[0]?0:1);
				int k2; if (d[0]&&d[1]) k2=1; else if (j2!=j) k2=1; else k2=0;
				chkmin(dp[i+1][j2][k2],tmp);
			}
		}
	}
	int all=0;
	for (int i=1;i<=n;i++) all+=(s[0][i]=='1')+(s[1][i]=='1');
	ans=INF;
	for (int j=0;j<=1;j++) for (int k=0;k<=1;k++) chkmin(ans,dp[n][j][k]);
	printf("%d\n",all-ans);
	return 0;
}