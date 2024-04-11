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

int n,mod,C[510][510],cnt[510];
int tmp,ans;
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int jc[510];
int dp[500*505],sum[500*505],s1[500*505],s2[500*505];

int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(mod);
	for (int x=1;x<=n;x++) for (int y=x+1;y<=n;y++) cnt[y-x]++;
	for (int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	jc[0]=1; for (int i=1;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod;
	dp[0]=1;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=i*i;j++) sum[j+1]=(sum[j]+dp[j])%mod;
		for (int j=0;j<=i*i;j++) {
			s1[j+1]=(s1[j]+sum[j])%mod;
			s2[j+1]=(s2[j]+(ll)sum[j]*j%mod)%mod;
		}
		int tmp=0;
		for (int j=0;j<=i*i;j++) {
			int l=max(1,j-i+1),r=j;
			if (l<r) {
				update(tmp,(ll)dp[j]*(s1[r]-s1[l]+mod)%mod*(i-j+mod)%mod);
				update(tmp,(ll)dp[j]*(s2[r]-s2[l]+mod)%mod);
			}
		}
		int A=n-i;
		update(ans,(ll)tmp*jc[A]%mod*C[n][A]%mod);
		for (int j=0;j<=i*i;j++) {
			dp[j]=sum[j+1];
			int bd=j-(i-1);
			if (bd>=0) update(dp[j],mod-sum[bd]);
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