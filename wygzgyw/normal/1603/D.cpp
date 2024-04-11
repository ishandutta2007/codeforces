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
const int maxn=(1e5)+10;
int T,n,k;
bool vis[maxn]; int tot,prime[maxn];
ll dp[maxn][20],sum[maxn],phi[maxn];
ll c(int l,int r) {
	ll res=0;
	for (int i;l<=r;l=i+1) {
		i=min(r,r/(r/l));
		res+=sum[r/l]*(i-l+1);
	}
	return res;
}
void solve(int l,int r,int L,int R,int k) {
	if (l>r) return;
	int mid=(l+r)>>1;
	int bd=min(R,mid),pos=bd;
	ll tmp,now=c(bd,mid),mn=1e18;
	for (int j=bd;j>=L;j--) {
		tmp=dp[j-1][k-1]+now;
		if (tmp<mn) pos=j,mn=tmp;
		if (j>L) now+=sum[mid/(j-1)];
	}
	dp[mid][k]=mn;
	solve(l,mid-1,L,pos,k);
	solve(mid+1,r,pos,R,k);
}
int main() {
	phi[1]=1;
	for (int i=2;i<maxn;i++) {
		if (!vis[i]) prime[++tot]=i,phi[i]=i-1;
		for (int j=1;j<=tot;j++) {
			if (prime[j]*i>=maxn) break;
			vis[i*prime[j]]=1;
			if (i%prime[j]==0) { phi[i*prime[j]]=phi[i]*prime[j]; break; }
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	for (int i=1;i<maxn;i++) sum[i]=sum[i-1]+phi[i];
	for (int i=1;i<maxn;i++) dp[i][1]=(ll)i*(i+1)/2;
	for (int i=2;i<=19;i++) solve(1,maxn-1,1,maxn-1,i);
	read(T); while (T--) {
		read(n); read(k);
		if (k>=20||(1<<k)>n) { printf("%d\n",n); continue; }
		printf("%lld\n",dp[n][k]);
	}
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