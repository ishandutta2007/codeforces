#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9)+10;
int n,x,y;
int val[50],dp[2][1<<22];
void init(int op) {
	for (int t=0;t<(1<<x);t++) dp[op][t]=-INF;
}
void update(int &x,int y) { if (x<y) x=y; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(x),read(y);
	if (x<y) swap(x,y); n--;
	for (int i=0;i<x+y;i++) {
		val[i]=n/(x+y)*(x+y)+i;
		if (val[i]>n) val[i]-=(x+y);
		if (val[i]<0) val[i]=0;
		else {
			val[i]/=(x+y); val[i]++;
		}
	//	printf("%d %d\n",i,val[i]);
	}
	init(1);
	dp[1][0]=0;
	int op=1,msk=(1<<x)-1;
	for (int i=0;i<x+y;i++) {
		init(op^1);
		for (int t=0,s;t<(1<<x);t++) if (dp[op][t]!=-INF) {
			s=(t<<1)&msk;
			//printf("%d %d %d\n",i,t,dp[op][t]);
			update(dp[op^1][s],dp[op][t]);
			if ((t>>(x-1))&1) continue;
			if ((t>>(y-1))&1) continue;
			update(dp[op^1][s+1],dp[op][t]+val[i]);
		}
		op^=1;
	}
	int ans=-INF;
	for (int t=0;t<(1<<x);t++) update(ans,dp[op][t]);
	printf("%d\n",ans);
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