#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
int n,n1,n2,ans,tmp,dp[2][3][410][410],cnt[30];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int T[30],f[2][2][410],all;
int dp1[410][410],dp2[410][410],f1[410],f2[410];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int get(int n) {
	return (ll)26*ksm(25,n-1)%mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); n1=n/2,n2=n-n1;
	//printf("MLE %d\n",(sizeof(dp))/1024/1024);
	for (int i=1;i<=26;i++) read(cnt[i]);
	all=(ll)get(n1)*get(n2)%mod;
	dp[1][0][0][0]=24,dp[1][1][1][0]=dp[1][2][0][1]=1;
	for (int i=1;i<=max(n1,n2);i++) {
		for (int op=0;op<3;++op) for (int j=0;j<=i+1;++j) for (int k=0;j+k<=i+1;++k) dp[i&1^1][op][j][k]=0;
		if (i==n1) {
			for (int op=0;op<3;++op) for (int j=0;j<=i;++j) for (int k=0;j+k<=i;k++)
				update(dp1[j][k],dp[i&1][op][j][k]);
		}
		if (i==n2) {
			for (int op=0;op<3;++op) for (int j=0;j<=i;++j) for (int k=0;j+k<=i;k++)
				update(dp2[j][k],dp[i&1][op][j][k]);
		}
		if (i==max(n1,n2)) break;
		for (int j=0;j<=i;++j)
		for (int k=0;j+k<=i;++k) {
			tmp=dp[i&1][0][j][k];
			if (tmp) {
				update(dp[i&1^1][0][j][k],(ll)tmp*23%mod);
				update(dp[i&1^1][1][j+1][k],tmp);
				update(dp[i&1^1][2][j][k+1],tmp);
			}
			tmp=dp[i&1][1][j][k];
			if (tmp) {
				update(dp[i&1^1][0][j][k],(ll)tmp*24%mod);
				update(dp[i&1^1][2][j][k+1],tmp);
			}
			tmp=dp[i&1][2][j][k];
			if (tmp) {
				update(dp[i&1^1][0][j][k],(ll)tmp*24%mod);
				update(dp[i&1^1][1][j+1][k],tmp);
			}
		}
	}
	f[1][0][0]=25,f[1][1][1]=1;
	for (int i=1;i<=max(n1,n2);i++) {
		for (int op=0;op<2;++op) for (int j=0;j<=i+1;++j) f[i&1^1][op][j]=0;
		if (i==n1) {
			for (int op=0;op<2;++op) for (int j=0;j<=i;++j)
				update(f1[j],f[i&1][op][j]);
		}
		if (i==n2) {
			for (int op=0;op<2;++op) for (int j=0;j<=i;++j)
				update(f2[j],f[i&1][op][j]);
		}
		if (i==max(n1,n2)) break;
		for (int j=0;j<=i;++j) {
			tmp=f[i&1][0][j];
			if (tmp) {
				update(f[i&1^1][0][j],(ll)tmp*24%mod);
				update(f[i&1^1][1][j+1],tmp);
			}
			tmp=f[i&1][1][j];
			if (tmp) {
				update(f[i&1^1][0][j],(ll)tmp*25%mod);
			}
		}
	}
	
	
	/*for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) {
		if (dp1[i][j]) printf("dp1[%d][%d]=%d\n",i,j,dp1[i][j]);
		if (dp2[i][j]) printf("dp2[%d][%d]=%d\n",i,j,dp2[i][j]);
	}
	for (int i=0;i<=n;i++) {
		if (f1[i]) printf("f1[%d]=%d\n",i,f1[i]);
		if (f2[i]) printf("f2[%d]=%d\n",i,f2[i]);
	}*/
	for (int i=n;i>=0;i--)
	for (int j=n;j>=0;j--) {
		update(dp2[i][j],((ll)dp2[i+1][j]+dp2[i][j+1]-dp2[i+1][j+1]+mod)%mod);
	}
	
	for (int i=1;i<=26;i++)
	for (int j=i+1;j<=26;j++) {
		tmp=0;
		for (int a=0;a<=n;a++)
		for (int b=0;b<=n;b++) if (dp1[a][b]) {
			update(tmp,(ll)dp1[a][b]*dp2[max(0,cnt[i]+1-a)][max(0,cnt[j]+1-b)]%mod);
		}
		update(T[i],tmp),update(T[j],tmp);
		update(ans,tmp);
		//if (tmp) printf("%d %d %d\n",cnt[i],cnt[j],tmp);
	}
	for (int i=n;i>=0;i--) update(f2[i],f2[i+1]);
	for (int i=1;i<=26;i++) {
		tmp=0;
		for (int a=0;a<=n;a++) {
			update(tmp,(ll)f1[a]*f2[max(0,cnt[i]+1-a)]%mod);
		}
		//if (tmp) printf("%d %d\n",cnt[i],tmp);
		update(ans,mod-T[i]);
		update(ans,tmp);
	}
	//printf("%d %d\n",all,ans);
	printf("%d\n",(all+mod-ans)%mod);
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