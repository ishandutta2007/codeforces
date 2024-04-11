#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=5050;
int n,m,ans,C[maxn][maxn],tmp;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=0;i<=5049;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for (int r=1;r<n;r++) {
		tmp=0;
		for (int c=m-1;c>=1;c--) {
			update(tmp,(ll)C[n-r+m-c-1][n-r]*C[c+n-r-1][n-r-1]%mod);
			update(ans,(ll)tmp*C[r+c-1][r]%mod*C[m-c+r-1][r-1]%mod);
		}
	}
	swap(n,m);
	for (int r=1;r<n;r++) {
		tmp=0;
		for (int c=m-1;c>=1;c--) {
			update(ans,(ll)tmp*C[r+c-1][r]%mod*C[m-c+r-1][r-1]%mod);
			update(tmp,(ll)C[n-r+m-c-1][n-r]*C[c+n-r-1][n-r-1]%mod);
		}
	}
	ans=(ll)ans*2%mod;
	printf("%d\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/