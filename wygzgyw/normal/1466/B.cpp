#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(2e5)+10;
int T,n,cnt[maxn];
int dp[maxn][2];
void update(int &x,int y) {
	if (x<y) x=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n*2+3;i++) cnt[i]=0,dp[i][0]=dp[i][1]=-INF;
		int x;
		for (int i=1;i<=n;i++) read(x),cnt[x]++;
		n=n*2+1;
		dp[1][0]=0;
		for (int i=1;i<=n;i++) {
			cnt[i]=min(cnt[i],2);
			for (int op=0;op<=1;op++) if (dp[i][op]!=-INF) {
				//printf("%d %d %d\n",i,op,dp[i][op]);
				if (cnt[i]==0) update(dp[i+1][0],dp[i][op]+op);
				else if (cnt[i]==1) update(dp[i+1][1],dp[i][op]+op),update(dp[i+1][0],dp[i][op]+1);
				else {
					update(dp[i+1][0],dp[i][op]+1);
					update(dp[i+1][1],dp[i][op]+1);
				}
			}
		}
		printf("%d\n",max(dp[n+1][0],dp[n+1][1]));
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/