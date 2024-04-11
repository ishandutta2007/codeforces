#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=2010;
int T,n;
char s[maxn],t[maxn];
int dp[maxn][maxn];
int c1[maxn][30],c2[maxn][30];
void update(int &x,int y) {
	if (x>y) x=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	int flag,x;
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		memset(c1[n+1],0,sizeof(c1));
		memset(c2[n+1],0,sizeof(c1));
		for (int i=n;i>=1;i--) {
			memcpy(c1[i],c1[i+1],sizeof(c1[i]));
			memcpy(c2[i],c2[i+1],sizeof(c2[i]));
			c1[i][s[i]-'a']++; c2[i][t[i]-'a']++;
		}
		flag=1;
		for (int i=0;i<26;i++)
			if (c1[1][i]!=c2[1][i]) { flag=0; break; }
		if (!flag) { printf("-1\n"); continue; }
		
		for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++) dp[i][j]=INF;
		
		for (int j=0;j<=n;j++) dp[0][j]=0;
		
		for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++) {
			x=t[j]-'a';
			if (c1[i+1][x]>c2[j+1][x]) update(dp[i][j],dp[i][j-1]);
			if (s[i]==t[j]) update(dp[i][j],dp[i-1][j-1]);
			update(dp[i][j],dp[i-1][j]+1);
		}
		printf("%d\n",dp[n][n]);
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