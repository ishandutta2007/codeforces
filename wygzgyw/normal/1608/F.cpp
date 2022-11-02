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
typedef long long ll;
const int mod=998244353;
const int maxn=2010;
int n,k,jc[maxn],ivjc[maxn],iv[maxn];
int dp[2][maxn][maxn],L[maxn],R[maxn],ans,tmp[maxn][maxn*2];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
int main() {
	read(n),read(k);
	iv[0]=jc[0]=ivjc[0]=iv[1]=jc[1]=ivjc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	for (int i=1;i<=n;i++) {
		int x; read(x);
		L[i]=max(0,x-k),R[i]=min(n+1,x+k);
	}
	dp[0][0][0]=1;
	for (int i=1;i<=n+1;i++) {
		for (int mex=L[i];mex<=R[i];++mex) for (int cnt=0;cnt<=i;++cnt) dp[i&1][mex][cnt]=0;
		for (int mex=L[i-1];mex<=R[i-1];++mex) {
			if (i<=n) {
				memset(tmp[mex],0,sizeof(tmp[mex]));
				if (mex>L[i-1]) memcpy(tmp[mex],tmp[mex-1],sizeof(tmp[mex]));
			}
			for (int cnt=0;cnt<=i;cnt++) if (dp[i&1^1][mex][cnt]) {
				if (i>n) { update(ans,(ll)dp[i&1^1][mex][cnt]*C(n-mex,cnt)%mod*jc[cnt]%mod); continue; }
				update(dp[i&1][mex][cnt],(ll)dp[i&1^1][mex][cnt]*(mex+cnt)%mod);
				update(dp[i&1][mex][cnt+1],dp[i&1^1][mex][cnt]);
				update(tmp[mex][mex+cnt],(ll)dp[i&1^1][mex][cnt]*jc[cnt]%mod);
		//  m>mex
		//	update(dp[i&1][m][cnt-(m-mex-1)],(ll)dp[i&1^1][mex][cnt]*jc[cnt]%mod*ivjc[cnt-(m-mex-1)]%mod);
			}
		}
		if (i>n) break;
		for (int m=L[i];m<=R[i];m++) for (int B=0;B<=i;B++) {
			int x=m-1; if (x>R[i-1]) x=R[i-1]; if (x<L[i-1]) continue;
			int y=B+m-1; if (y<0||y>n*2) continue;
			update(dp[i&1][m][B],(ll)tmp[x][y]*ivjc[B]%mod);
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