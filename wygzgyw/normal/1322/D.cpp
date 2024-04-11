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
const int INF=0x7f7f7f7f;
const int bd=12;
int n,m,l[4030],s[4030],c[4030];
int dp[2030][1<<bd],sum[bd+5];
void chkmax(int &x,int y) { if (x<y) x=y; }
int d[2030][1<<bd],pre[4030];
int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) read(l[i]);
	for (int i=1;i<=n;i++) read(s[i]);
	for (int i=1;i<=n+m;i++) read(c[i]);
	for (int i=1;i<=m;i++) for (int t=0;t<(1<<bd);t++) d[i][t]=-INF;
	for (int i=1;i<=n;i++) for (int t=0;t<(1<<bd);t++) dp[i][t]=-INF;
	for (int i=1;i<=n;i++) dp[i][1]=0;
	int ans=0;
	for (int i=n;i>=1;i--) {
		for (int t=1;t<(1<<bd);t++) chkmax(dp[i][t],d[l[i]][t]);
		chkmax(dp[i][1],pre[l[i]]);		
		int mx=-INF;
		for (int t=1;t<(1<<bd);++t) {
			if (dp[i][t]!=-INF) {
				dp[i][t]+=c[l[i]]-s[i];
				for (int j=0;j<bd;++j) {
					sum[j]=0;
					for (int k=j;k<bd;++k) if (t&(1<<k)) sum[j]+=c[k+1+l[i]]; else break;
				}
				//printf("%d %d %d\n",i,t,dp[i][t]);
				chkmax(ans,dp[i][t]);
				for (int j=l[i];j<=min(m,l[i]+bd+1);j++) {
					chkmax(d[j][(t>>(j-l[i]))+1],dp[i][t]+sum[j-l[i]]);
				}
				chkmax(mx,dp[i][t]);
				
				/*for (int j=1;j<i;j++) if (l[j]>=l[i]) {
					int tmp=0; if (l[j]<=l[i]+bd+1) tmp=sum[l[j]-l[i]];
					chkmax(dp[j][(t>>(l[j]-l[i]))+1],dp[i][t]-s[j]+tmp+c[l[j]]);
				}*/
			}
		}
		if (mx!=-INF) {
			for (int j=min(m,l[i]+bd+1)+1;j<=m;j++) chkmax(pre[j],mx);
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