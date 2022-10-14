#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,k,p[4][N];
ll x[N],y[N];

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) {
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x[i]=(x1+x2);
		y[i]=(y1+y2);
	}
	rep(i,1,n+1) rep(j,0,4) p[j][i]=i;
	sort(p[0]+1,p[0]+1+n,[&](int i,int j) {
		return x[i]<x[j];
	});
	sort(p[1]+1,p[1]+1+n,[&](int i,int j) {
		return x[i]>x[j];
	});
	sort(p[2]+1,p[2]+1+n,[&](int i,int j) {
		return y[i]<y[j];
	});
	sort(p[3]+1,p[3]+1+n,[&](int i,int j) {
		return y[i]>y[j];
	});
	multiset<ll> X,Y;
	rep(i,1,n+1) {
		X.insert(x[i]);
		Y.insert(y[i]);
	}
	ll ans=1e18;
	rep(i1,0,k+1) rep(i2,0,k+1) rep(i3,0,k+1) rep(i4,0,k+1) {
		set<int> st;
		rep(i,0,i1) st.insert(p[0][i+1]);
		rep(i,0,i2) st.insert(p[1][i+1]);
		rep(i,0,i3) st.insert(p[2][i+1]);
		rep(i,0,i4) st.insert(p[3][i+1]);
		if (SZ(st)!=k) continue;
		for (auto id:st) {
			X.erase(X.find(x[id]));
			Y.erase(Y.find(y[id]));
		}
		ll mn_X=(ll)(*X.begin());
		ll mx_X=(ll)(*prev(X.end()));
		ll mn_Y=(ll)(*Y.begin());
		ll mx_Y=(ll)(*prev(Y.end()));
		ll sdx=mx_X-mn_X,sdy=mx_Y-mn_Y;
		if (sdx==0) sdx+=2;
		if (sdy==0) sdy+=2;
		ll P=sdx*sdy,nans=P/4;
		if (P%4!=0) nans++;
		if (sdx!=0&&sdy!=0) {
			//printf("%lld %lld %lld %lld\n",mn_X,mx_X,mn_Y,mx_Y);
			ans=min(ans,nans);
		} 
		for (auto id:st) {
			X.insert(x[id]);
			Y.insert(y[id]);
		}
	}
	printf("%lld",ans);
}