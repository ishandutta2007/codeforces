#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T;
char s[1010];
int dp[110][2][2];
int n,tmp;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1); n=strlen(s+1);
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		int ans=0;
		for (int i=0;i<=n;i++) {
			for (int chose=0;chose<=1;chose++) {
				for (int now=0;now<=1;now++) if (dp[i][chose][now]) {
					if (i==n) { ans=1; continue; }
					for (int nxt=0;nxt<=1;nxt++) {
						if (chose&&nxt) continue;
						if (now&&!nxt&&s[i+1]=='0') continue;
						tmp=now;
						if (!nxt&&s[i+1]=='1') tmp=1;
						dp[i+1][nxt][tmp]=1;
					}
				}
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
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