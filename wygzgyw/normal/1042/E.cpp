#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=1010;
const ll mod=998244353;
int n,m,a[maxn][maxn],tot,x,y;
ll dp[maxn][maxn],sqrx,sqry,sx,sy,sdp;
ll SQRX,SQRY,SX,SY;
struct node {
	int val,x,y;
} d[maxn*maxn];
ll sqr(ll x) {
	return x*x%mod;
}
ll ksm(ll x,ll y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	ll res=ksm(x,y/2);
	res=res*res%mod;
	if (y%2==1) res=res*x%mod;
	return res;
}
bool cmp(node a,node b) {
	return a.val<b.val;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		read(a[i][j]);
		d[++tot]=(node){a[i][j],i,j};
	}
	sort(d+1,d+(tot+1),cmp);
	int lst=1;
	for (int i=1;i<=tot+1;i++) {
		if (i>1&&d[i].val!=d[i-1].val) {
			int l=lst,r=i-1;
			ll tmp=0;
			for (int j=l;j<=r;j++) {
				ll res=(sdp+sqr(d[j].x)*(l-1)%mod)%mod-2LL*sx%mod*d[j].x%mod+mod+sqrx; res%=mod;
				res+=sqr(d[j].y)*(l-1)%mod-2LL*sy%mod*d[j].y%mod+mod+sqry; res%=mod;
				res*=ksm(l-1,mod-2); res%=mod;
				dp[d[j].x][d[j].y]=res;
				tmp+=res; tmp%=mod;
			}
			sdp+=tmp;
			sdp%=mod;
			lst=i;
			sqrx+=SQRX; sqrx%=mod;
			sqry+=SQRY; sqry%=mod;
			sx+=SX; sx%=mod;
			sy+=SY; sy%=mod;
			SQRX=SQRY=SX=SY=0;
		}
		SQRX+=sqr(d[i].x); SQRX%=mod;
		SQRY+=sqr(d[i].y); SQRY%=mod;
		SX+=d[i].x; SX%=mod;
		SY+=d[i].y; SY%=mod;
	}
	read(x); read(y);
	printf("%lld\n",dp[x][y]);
	return 0;
}