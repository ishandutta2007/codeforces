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

const int N=1005;
int n,k,del[N];

int main() {
	scanf("%d%d",&n,&k);
	vector<VI> a(n,VI(k));
	rep(i,0,n) rep(j,0,k) scanf("%d",&a[i][j]);
	sort(all(a));
	ll ans=0;
	rep(i,0,n) rep(j,i+1,n) {
		VI v(k);
		rep(p,0,k) {
			if (a[i][p]==a[j][p]) v[p]=a[i][p];
			else v[p]=0^1^2^a[i][p]^a[j][p];
		}
		auto it=lower_bound(all(a),v);
		if (it!=a.end()&&*it==v) {
			int idx=it-a.begin();
			ans+=del[idx];
			del[idx]++;
		}
	}
	printf("%lld",ans);
}