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
const int mod=(1e9)+7;
const int maxn=1010;
const int B=13;
int n;
int jc[maxn],iv[maxn],ivjc[maxn];
void init(){jc[0]=jc[1]=iv[0]=iv[1]=ivjc[0]=ivjc[1]=1;for(int i=2;i<maxn;++i)jc[i]=(ll)jc[i-1]*i%mod,iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod,ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;}
inline int C(int n,int m){return n<m||m<0?0:(ll)jc[n]*ivjc[m]%mod*ivjc[n-m]%mod;}
ll z;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int dp[2][1<<B][2];
int Get(ll r,int k) {
	if (k>61) return 0;
	return r>>k&1;
}
int solve(ll r) {
	memset(dp,0,sizeof(dp));
	int ans=0;
	int op=0;
	dp[0][0][1]=1;
	for (int i=0;i<=61;i++) {
		memset(dp[op^1],0,sizeof(dp[op^1]));
		for (int t=0;t<(1<<B);t++) for (int k=0;k<=1;k++) if (dp[op][t][k]) {
			for (int v=(z>>i&1);v<=n;v+=2) {
				int s=t+v;
				int tmp=(s&1),R=Get(r,i);
				s>>=1;
				int k2=k;
				if (tmp<R) k2=0;
				else if (tmp>R) k2=1;
				update(dp[op^1][s][k2],(ll)dp[op][t][k]*C(n,v)%mod);
			}
		}
		op^=1;
	}
	return dp[op][0][0];
	/*
	for (int t=0;t<(1<<B);t++) for (int k=0;k<=1;k++) {
		if (k) {
			if (t>(r&((1<<B)-1))) continue;
		}
		update(ans,dp[op][t][k]);
	}
	return ans;*/
}
int main() {
	ll l,r;
	read(n),read(l),read(r),read(z); init();
	printf("%d\n",(solve(r+1)-solve(l)+mod)%mod);
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