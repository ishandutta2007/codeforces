#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
int n,K;
int dp[210][210][410];
int fm[210][210];
int tmp,fz[410][410];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int ivjc[210],pre[210][210];
int ans[210];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(K);
	tmp=1;
	for (int i=1;i<=205;i++) {
		tmp=(ll)tmp*ksm(i,mod-2)%mod;
		fm[i][0]=1;
		for (int x=1;x<=205;x++) fm[i][x]=(ll)fm[i][x-1]*tmp%mod;
	}
	for (int i=0;i<=405&&i<=n;i++) {
		fz[i][0]=1;
		for (int x=1;x<=405;x++) {
			fz[i][x]=(ll)fz[i][x-1]*(n-i-x+1)%mod;
		}
	}
	pre[0][1]=1; ivjc[0]=1;
	for (int i=1;i<=205;i++) {
		pre[i][1]=(ll)pre[i-1][1]*i%mod;
		pre[i][0]=1;
		ivjc[i]=ksm(pre[i][1],mod-2);
		for (int x=2;x<=205;x++) pre[i][x]=(ll)pre[i][x-1]*pre[i][1]%mod;
	}
	dp[1][0][0]=1;
	for (int cnt=1;cnt<=K+1;cnt++) {
		for (int i=0;i<=K;i++) {
			for (int j=0;j<=K*2&&j<=n;j++) if (dp[cnt][i][j]) {
				//printf("%d %d %d %d\n",cnt,i,j,dp[cnt][i][j]);
				for (int x=0;x*cnt+i<=K&&j+x*(cnt+1)<=n;x++) {
					tmp=(ll)fz[j][x*(cnt+1)]*fm[cnt+1][x]%mod;
					tmp=(ll)tmp*ivjc[x]%mod*pre[cnt][x]%mod;
					/*assert(j<=405&&x*(cnt+1)<=405);
					assert(cnt+1<=205&&x<=205);
					assert(x<=205&&cnt<=205&&x<=205);*/
					//printf("x=%d %d %d\n",x,x*cnt+i,tmp);
					update(dp[cnt+1][x*cnt+i][j+x*(cnt+1)],(ll)dp[cnt][i][j]*tmp%mod);
				}	
			}
		}
	}
	for (int i=0;i<=K;i++) {
		tmp=0;
		for (int j=0;j<=K*2&&j<=n;j++) {
			update(tmp,dp[K+1][i][j]);
		}
		ans[i]=tmp;
		//printf("?? %d\n",tmp);
	}
	for (int i=1;i<=K;i++) {
		if (i-2>=0) update(ans[i],ans[i-2]);
		printf("%d ",ans[i]);
	}
	puts("");
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