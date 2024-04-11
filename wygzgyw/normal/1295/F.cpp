#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=998244353;
int n,d[210],tot,l[60],r[60];
ll dp[51][210],iv[210],ivjc[210];
ll ans,tmp;
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
ll C(int x,int y) {
	if (x<y||y<0) return 0;
	if (x==y||y==0) return 1;
	ll res=1;
	for (int i=x;i>=x-y+1;i--) res=res*i%mod;
	return res*ivjc[y]%mod;
}
void update(ll &x,ll y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	iv[0]=ivjc[0]=1;
	iv[1]=ivjc[1]=1;
	for (int i=2;i<=n;i++)
		iv[i]=(mod-mod/i)*iv[mod%i]%mod,
		ivjc[i]=ivjc[i-1]*iv[i]%mod;
	for (int i=n;i>=1;i--) {
		read(l[i]),read(r[i]);
		d[++tot]=l[i];
		d[++tot]=r[i];
		d[++tot]=l[i]-1;
	}
	sort(d+1,d+tot+1);
	tot=unique(d+1,d+tot+1)-d-1;
	/*for (int i=1;i<=n;i++)
		x[i]=lower_bound(d+1,d+tot+1,l[i])-d,
		y[i]=lower_bound(d+1,d+tot+1,r[i])-d;*/
//	for (int i=1;i<=tot;i++) printf("%d ",d[i]); printf("\n");
	dp[0][0]=1;
	d[0]=-1;
	for (int j=0;j<=tot;j++) {
		for (int i=0;i<=n;i++) {
			if (!dp[i][j]) continue;
		//	printf("%d %d %lld\n",i,j,dp[i][j]);
			update(dp[i][j+1],dp[i][j]);
			for (int k=i+1;k<=n;k++) {
				if (l[k]<=d[j]+1&&d[j+1]<=r[k]) {
					tmp=dp[i][j]*C(d[j+1]-d[j]+k-i-1,k-i)%mod;
					update(dp[k][j+1],tmp);
				} else break;
			}
		}
	}
	ans=dp[n][tot];
	for (int i=1;i<=n;i++)
		ans=ans*ksm(r[i]-l[i]+1,mod-2)%mod;
	printf("%lld\n",ans);
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