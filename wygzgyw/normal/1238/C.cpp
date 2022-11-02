#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(2e5)+10;
int T,n,ans;
int d[maxn];
int dp[maxn];
int dfs(int x,int i) {
	while (d[i]>=x&&i<=n) i++;
	x=d[i]+1;
	if (x<=2) return dp[i]=0;
	if (dp[i]!=INF) return dp[i];
	dp[i]=dfs(x-1,i)+1;
	int tmp=dfs(x-2,i);
	if (d[i+1]!=x-2) tmp++;
	dp[i]=min(dp[i],tmp);
	return dp[i];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(n); ans=0;
		for (int i=1;i<=n;i++) read(d[i]);
		d[n+1]=0;
		for (int i=1;i<=n;i++) dp[i]=INF;
		printf("%d\n",dfs(d[1],1));
	}
	return 0;
}