#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=0x7f7f7f7f;
const int N=250,M=28;
int n,dp[2][70][260][260];
char s[100];
void update(int &x,int y) { if (x>y) x=y; }
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1); n=strlen(s+1); reverse(s+1,s+n+1);
	s[++n]='0';
	memset(dp,INF,sizeof(dp));
	dp[0][M][N-1][N-1]=0;
	for (int i=1;i<=n;i++) {
		memset(dp[1],INF,sizeof(dp[1]));
		for (int carry=0;carry<=M*2;carry++)
		for (int cp=N-1;cp>=0;cp--)
		for (int cn=N-1;cn>=0;cn--) if (dp[0][carry][cp][cn]!=INF) {
			if (cp>0) update(dp[0][carry][cp-1][cn],dp[0][carry][cp][cn]);
			if (cn>0) update(dp[0][carry][cp][cn-1],dp[0][carry][cp][cn]);
			int rcarry=carry-M;
			int val=rcarry+cp-cn;
			int digit=(val%10+10)%10;
			int ncarry=val/10;
			if (val<0&&digit!=0) ncarry--;
			if (digit==s[i]-'0') update(dp[1][ncarry+M][cp][cn],dp[0][carry][cp][cn]+cp+cn);
		}
		swap(dp[0],dp[1]);
	}
	int ans=INF;
	for (int i=0;i<N;i++) for (int j=0;j<N;j++) update(ans,dp[0][M][i][j]);
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/