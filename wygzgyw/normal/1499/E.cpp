#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
char x[1010],y[1010];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int dp[1010][1010][2];
int a[1010],b[1010];
int n,m,ans;

int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",x+1); scanf("%s",y+1);
	n=strlen(x+1),m=strlen(y+1);
	a[1]=1;
	for (int i=2;i<=n;i++) {
		if (x[i-1]!=x[i]) a[i]=a[i-1]+1; else a[i]=1;
	}
	b[1]=1;
	for (int i=2;i<=m;i++) {
		if (y[i-1]!=y[i]) b[i]=b[i-1]+1; else b[i]=1;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (i>1&&x[i-1]!=x[i]) update(dp[i][j][0],dp[i-1][j][0]);
			if (x[i]!=y[j]) {
				update(dp[i][j][0],b[j]);
				update(dp[i][j][0],dp[i-1][j][1]);
			}
			if (j>1&&y[j-1]!=y[j]) update(dp[i][j][1],dp[i][j-1][1]);
			if (x[i]!=y[j]) {
				update(dp[i][j][1],a[i]);
				update(dp[i][j][1],dp[i][j-1][0]);
			}
			update(ans,dp[i][j][0]);
			update(ans,dp[i][j][1]);
		}
	}
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