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

int n,r[3],c[3],_,x,y;

int f(int* a) {
	if (a[0]==a[1]||a[0]==a[2]) return a[0];
	else return a[1];
}

void solve() {
	scanf("%d",&n);
	rep(i,0,3) scanf("%d%d",r+i,c+i);
	scanf("%d%d",&x,&y);
	int fr=f(r),fc=f(c);
	for (auto&p:{mp(1,1),mp(1,n),mp(n,1),mp(n,n)}) {
		if (fr==p.fi&&fc==p.se) {
			if (x==p.fi||y==p.se) {
				puts("YES");
			} else {
				puts("NO");
			}
			return;
		}
	}
	fr=(r[0]^r[1]^r[2]);
	fc=(c[0]^c[1]^c[2]);
	if ((x%2==fr%2)&&(y%2==fc%2)) {
		puts("NO");
	} else {
		puts("YES");
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}