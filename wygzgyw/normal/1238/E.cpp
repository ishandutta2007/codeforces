#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=0x7f7f7f7f;
const int maxn=(1e5)+10;
int n,m,cnt[30][30];
int dp[1<<20];
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	scanf("%s",s+1);
	int x,y;
	for (int i=2;i<=n;i++) {
		x=s[i-1]-'a'+1;
		y=s[i]-'a'+1;
		cnt[x][y]++; cnt[y][x]++;
	}
	for (int i=1;i<=m;i++) cnt[i][i]=0;
	memset(dp,INF,sizeof(dp));
	dp[0]=0;
	for (int t=0;t<(1<<m);t++) {
		x=0;
		for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++) {
			y=0;
			if (t&(1<<(i-1))) y++;
			if (t&(1<<(j-1))) y++;
			if (y&1) x+=cnt[i][j];
		}
		for (int i=1;i<=m;i++)
			if (t&(1<<(i-1))) dp[t]=min(dp[t],dp[t-(1<<(i-1))]+x);
	}
	printf("%d\n",dp[(1<<m)-1]);
	return 0;
}