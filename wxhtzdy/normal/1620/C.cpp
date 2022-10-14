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

const int N=2050;
int _,n,k;
ll x;
char s[N],t[N*N];

void solve() {
	scanf("%d%d%lld",&n,&k,&x);
	x--;
	scanf("%s",s);
	int len=0,cc=0;
	per(i,0,n) {
		if (s[i]=='*') cc++	;
		else {
			rep(j,0,x%(cc*k+1)) t[len++]='b';
			t[len++]='a';
			x/=(cc*k+1);
			cc=0;
		}
	}
	rep(j,0,x%(cc*k+1)) t[len++]='b';
	per(i,0,len) printf("%c",t[i]); puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}