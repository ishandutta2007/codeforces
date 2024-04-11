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

//c[i]=c[i+1]+c[i-1]-c[i]

// c[i]-c[i-1],c[i+1]-c[i],...
// c[i+1]-c[i],c[i]-c[i-1]

const int N=105000;
int n,c[N],t[N];

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",c+i);
	rep(i,1,n+1) scanf("%d",t+i);
	if (c[1]!=t[1]||c[n]!=t[n]) {
		puts("No");
		return 0;
	}
	VI dx,dy;
	rep(i,1,n) dx.pb(c[i+1]-c[i]);
	rep(i,1,n) dy.pb(t[i+1]-t[i]);
	sort(all(dx));
	sort(all(dy));
	rep(i,0,SZ(dx)) {
		if (dx[i]!=dy[i]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}