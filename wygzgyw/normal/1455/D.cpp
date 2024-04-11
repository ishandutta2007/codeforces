#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=0x7f7f7f7f;
int T,n,x,a[510];
int dp[510][510],ans;
void update(int &x,int y) {
	if (x>y) x=y;
}
int f(int k,int j,int i) {
	if (k==i) return a[j];
	return a[k];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(x); a[0]=x;
		for (int i=1;i<=n;i++) read(a[i]);
		memset(dp,INF,sizeof(dp));
		int flag=1;
		for (int i=1;i<n;i++)
			if (a[i]>a[i+1]) { flag=0; break; }
		if (flag) { printf("0\n"); continue; }
		for (int i=1;i<=n;i++) {
			if (a[i-1]<=x&&a[i]>x) dp[0][i]=1;
			if (i>1&&a[i-1]>a[i]) break;
		}
		for (int j=0;j<=n;j++)
		for (int i=j+1;i<=n;i++) {
			flag=1;
			for (int k=j+1;k<i-1;k++)
				if (a[k]>a[k+1]) { flag=0; break; }
			if (!flag||f(i-1,j,i)>a[j]||a[i]<=a[j]) continue;
			for (int k=0;k<j;k++)
				if (a[k]<=f(j+1,j,i)) update(dp[j][i],dp[k][j]+1);
			//if (dp[j][i]<INF) printf("%d %d %d\n",j,i,dp[j][i]);
		}
		ans=INF;
		for (int j=0;j<=n;j++)
		for (int i=1;i<=n;i++) {
			flag=1;
			for (int k=i;k<n;k++)
				if (f(k,j,i)>a[k+1]) { flag=0; break; }
			if (flag) update(ans,dp[j][i]);
		}
		if (ans==INF) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}