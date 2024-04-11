// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
int T,n,len; char s[1000];
string dp[55][1<<10],ans;
int pos[15][55][2];
void update(string &s,string t) { if (s.size()<t.size()) s=t; }
string dfs(int c,int msk) {
	if ((int)dp[c][msk].size()>0) return dp[c][msk];
	//printf("%d %d\n",c,msk);
	for (int i=0;i<52;i++) {
		int nxt=0,flag=1;
		for (int j=1;j<=n;j++) {
			int p=pos[j][c][msk>>(j-1)&1];
			if (pos[j][i][0]>p);
			else if (pos[j][i][1]>p) nxt|=(1<<(j-1));
			else { flag=0; break; }
		}
		if (flag) {
			update(dp[c][msk],dfs(i,nxt));
		}
	}
	dp[c][msk]+=(c<26?c+'a':c+'A'-26); return dp[c][msk];
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=0;i<52;i++) for (int j=0;j<(1<<n);j++) dp[i][j]="";
		for (int i=1;i<=n;i++) {
			scanf("%s",s+1); len=strlen(s+1);
			for (int j=0;j<52;j++) pos[i][j][0]=pos[i][j][1]=-1;
			for (int j=1;j<=len;j++) {
				int t=('a'<=s[j]&&s[j]<='z'?s[j]-'a':s[j]-'A'+26);
				if (pos[i][t][0]==-1) pos[i][t][0]=j; else pos[i][t][1]=j;
			}
		}
		ans="";
		for (int i=0;i<52;i++) {
			int flag=1;
			for (int j=1;j<=n;j++) flag&=(pos[j][i][0]!=-1);
			if (flag) update(ans,dfs(i,0));
		}
		printf("%d\n",(int)ans.size());
		reverse(ans.begin(),ans.end()); cout<<ans<<endl;
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