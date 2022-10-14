#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=200050,L=25;
int _,n,q,a[N],b[N],st[N][L],logs[N],f[N],ff[N];
ll pref[N],pref2[N];
VI ids[N];

int query(int l,int r) {
	int k=logs[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}

ll qsum(int l,int r) {
	ll res=pref[r];
	if (l>0) res-=pref[l-1];
	return res;
}

ll fsum(int l,int r) {
	ll res=pref2[r];
	if (l>0) res-=pref2[l-1];
	return res;
}

void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,2,n+1) logs[i]=logs[i>>1]+1;
	rep(i,0,n) b[i]=a[i]-(i+1);
	rep(i,0,n) st[i][0]=b[i];
	rep(j,1,L) rep(i,0,n) if (i+(1<<j)<=n) st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	rep(i,0,n) {
		int l=i,r=n-1,pp=i;
		while (l<=r) {
			int mid=l+r>>1;
			if (query(i,mid)+i>=0) pp=mid,l=mid+1;
			else r=mid-1;
		}
		f[i]=pp;
		ids[pp+1].pb(i);
		if (pp>=n-2) {
			ff[i]=n-1;
			continue;
		}
		pp++;
		pp=min(pp,n-1);
		l=pp+1,r=n-1;
		int qp=pp+1;
		while (l<=r) {
			int mid=l+r>>1;
			if (query(qp,mid)+i>=0) pp=mid,l=mid+1;
			else r=mid-1;
		}
//		printf("%d %d %d\n",i,pp,qp);
		ff[i]=pp;
	}
	rep(i,1,n) assert(f[i]>=f[i-1]);
	ll s=0;
	rep(i,0,n) s+=f[i]-i+1;
	pref[0]=f[0];
	rep(i,1,n) pref[i]=pref[i-1]+f[i];
	pref2[0]=ff[0];
	rep(i,1,n) pref2[i]=pref2[i-1]+ff[i];
	scanf("%d",&q);
	while (q--) {
		int p,x;
		scanf("%d%d",&p,&x); --p;
		if (a[p]>=x) {
			int l=0,r=p-1,pp=p;
			while (l<=r) {
				int mid=l+r>>1;
				if (f[mid]>=p) pp=mid,r=mid-1;
				else l=mid+1;
			}
			if (pp==p||x-(p-pp)>=1) {
				printf("%lld\n",s);
				continue;
			}
			int qp=pp;
			l=pp,r=p-1,pp=p-1;
			while (l<=r) {
				int mid=l+r>>1;
				if (x-(p-mid)<1) pp=mid,l=mid+1;
				else r=mid-1;
			}
			ll ans=s;
			ans-=qsum(qp,pp);
			ans+=(p-1)*1LL*(pp-qp+1);
			printf("%lld\n",ans);
		} else {
			if (ids[p].empty()) {
				printf("%lld\n",s);
				continue;
			}
			if (x<(p-ids[p].back()+1)) {
				printf("%lld\n",s);
				continue;
			}
			int l=0,r=ids[p].size()-1,pp=0;
			while (l<=r) {
				int mid=l+r>>1;
				if (x>=(p-ids[p][mid]+1)) pp=mid,r=mid-1;
				else l=mid+1;
			}
			ll ans=s;
//			printf("%lld  ",ans);
//			printf("[%d, %d] ", ids[p][pp],ids[p].back());
			ans-=qsum(ids[p][pp],ids[p].back());
//			printf("%lld  ",ans);
			ans+=fsum(ids[p][pp],ids[p].back());
			printf("%lld\n",ans);
		}
	}
}

int main() {
	solve();
}