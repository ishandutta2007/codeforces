#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,m,tot,ans;
int d[5][110];
int dp[110][1<<4];
int f[5];
void update(int &x,int y) {
	if (x<=y) x=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	//freopen("1.out","w",stdout);
	read(T);
	while (T--) {
		read(n); read(m); tot=ans=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			read(d[i][j]);
		memset(dp,0,sizeof(dp));
		int msk,tmp;
		for (int j=0;j<m;j++)
		for (int t=0;t<(1<<n);t++) {
			for (int i=0;i<n;i++) {
				for (int k=1;k<=n;k++)
					if (k+i>n) f[k+i-n]=d[k][j+1];
					else f[k+i]=d[k][j+1];
				msk=(1<<n)-1-t;
				for (int s=msk;;s=(s-1)&msk) {
					tmp=0;
					for (int k=1;k<=n;k++)
					if (s&(1<<(k-1))) tmp+=f[k];
					update(dp[j+1][t+s],dp[j][t]+tmp);
					if (!s) break;
				}
			}
		}
		printf("%d\n",dp[m][(1<<n)-1]);
	}
	return 0;
}