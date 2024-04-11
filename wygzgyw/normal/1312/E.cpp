#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
int n,a[510],dp[510][510],f[510];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int len=1;len<=n;len++) {
		for (int l=1,r;l+len-1<=n;l++) {
			r=l+len-1;
			if (len==1) { dp[l][r]=a[l]; continue; }
			for (int k=l;k<r;k++)
				if (dp[l][k]&&dp[l][k]==dp[k+1][r]) dp[l][r]=dp[l][k]+1;
		}
	}
	for (int i=1;i<=n;i++) {
		f[i]=INF;
		for (int j=0;j<i;j++)
			if (dp[j+1][i])
				f[i]=min(f[i],f[j]+1);
	}
	printf("%d\n",f[n]);
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