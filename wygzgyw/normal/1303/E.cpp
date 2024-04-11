#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=410;
int T,n,m,dp[maxn][maxn];
char s[maxn],t[maxn];
void update(int &x,int y) {
	if (x<y) x=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		int pos=1;
		for (int i=1;i<=n;i++)
			if (pos<=m&&s[i]==t[pos]) pos++;
		if (pos>m) { printf("YES\n"); continue; }
		bool flag=0;
		//ababcd
		//abcba
		for (int mid=1;mid<m;mid++) {
			memset(dp,0,sizeof(dp));
			dp[0][0]=mid;
			for (int i=0;i<n;i++) {
				for (int j=0;j<=mid;j++) {
					if (!dp[i][j]) continue;
					update(dp[i+1][j],dp[i][j]);
					if (j<mid&&s[i+1]==t[j+1])
						update(dp[i+1][j+1],dp[i][j]);
					if (dp[i][j]<m&&s[i+1]==t[dp[i][j]+1])
						update(dp[i+1][j],dp[i][j]+1);
				}
			}
			if (dp[n][mid]==m) { flag=1; break; }
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
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