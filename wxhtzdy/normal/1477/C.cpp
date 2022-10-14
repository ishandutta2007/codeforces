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

const int N=5005;
int n,x[N],y[N];
bool was[N];

ll dist(ll x1,ll y1,ll x2,ll y2) {
	return abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2);
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",x+i,y+i);
	VI ans(1,0);
	was[0]=1;
	rep(k,0,n-1) {
		int i=ans[k];
		int mx=i;
		rep(j,0,n) if (!was[j]&&dist(x[i],y[i],x[j],y[j])>dist(x[i],y[i],x[mx],y[mx])) mx=j;
		was[mx]=true;
		ans.pb(mx);
	}
	rep(i,0,n) printf("%d ",ans[i]+1);
}