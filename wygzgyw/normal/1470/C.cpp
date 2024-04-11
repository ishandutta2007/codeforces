#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,k,tim,p,dp[2][100010];
int Nxt(int &j) {
	if (j==n-1) return 0;
	return j+1;
}
int pre(int &j) {
	if (j==0) return n-1;
	return j-1;
}
int query(int x) {
	x=(x%n+n)%n;
	tim++;
	/*for (register int j=0;j<n;++j) {
		dp[tim&1][j]=0;
	}
	for (register int j=0;j<n;j++) {
		if (j==0) dp[tim&1][Nxt(j)]+=dp[tim&1^1][j];
		else dp[tim&1][Nxt(j)]+=dp[tim&1^1][j]-dp[tim&1^1][j]/2,dp[tim&1][pre(j)]+=dp[tim&1^1][j]/2;
	}*/
	printf("? %d\n",x+1);
	fflush(stdout);
	scanf("%d",&x);
	return x;
//	return dp[tim&1][(x-p+n)%n];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
//	read(p); p--;
//	p=rand()%n;
	int block=sqrt(n)-1;
	for (int i=0;i<n;i++) dp[0][i]=k;
	for (int i=1;i<=block;i++) query(0);
	int x=0;
	while (1) {
		if (query(x)>k) break;
		x=(x+block)%n;
	}
	//printf("%d %d\n",x,tim);
	int l=0,r=tim,mid,res=-1;
	while (l<=r) {
		mid=(l+r)>>1;
		if (query(x-mid)>=k) res=mid,l=mid+1;
		else r=mid-1;
	}
	//for (int j=0;j<=x;j++) printf("%d ",dp[tim&1][j]); printf("\n");
	//for (int j=n-20;j<n;j++) printf("%d ",dp[tim&1][j]); printf("\n");
	//printf("? %d\n",query(x-res));
	printf("! %d\n",(x-res+n)%n+1);
	fflush(stdout);
//	printf("%d\n",p+1);
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