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
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int _,n,p[N],x,a,y,b,ans[N];
ll k;
bool check(int t) {
	VI cc(3);
	rep(i,0,t) {
		if ((i+1)%a==0&&(i+1)%b==0) cc[0]++;
		else if ((i+1)%a==0) cc[1]++;
		else if ((i+1)%b==0) cc[2]++;
	}
	VI vl; rep(i,0,n) vl.pb(p[i]);
	sort(all(vl)); reverse(all(vl));
	ll sum=0;
	rep(i,0,SZ(vl)) {
		if (cc[0]>0) sum+=vl[i]*(x+y),cc[0]--;
		else if (cc[1]>0) sum+=vl[i]*x,cc[1]--;
		else if (cc[2]>0) sum+=vl[i]*y,cc[2]--;
	}
	return sum>=k;
}
void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",p+i),p[i]/=100;
	scanf("%d%d%d%d%lld",&x,&a,&y,&b,&k);
	if (x<y) swap(x,y),swap(a,b);
	int l=1,r=n,ans=-1;
	while (l<=r) {
		int md=(l+r)>>1;
		if (check(md)) ans=md,r=md-1;
		else l=md+1;
	}
	printf("%d\n",ans);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}