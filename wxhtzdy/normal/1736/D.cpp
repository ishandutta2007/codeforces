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

const int N=200050;
int n,_,c[2];
char s[N];

void solve() {
	scanf("%d",&n);
	scanf("%s",s);
	n*=2;
	c[0]=c[1]=0;
	rep(i,0,n) c[s[i]-'0']++;
	if (c[0]&1) {
		puts("-1");
		return;
	}
	VI pp;
	for (int i=0;i<n;i+=2) {
		if (s[i]==s[i+1]) continue;
		pp.pb(i);
	}
	assert(SZ(pp)%2==0);
	VI b;
	rep(id,0,SZ(pp)) {
		int i=pp[id];
		int md=SZ(b)%2;
		char ch=(char)('0'+md);
		if (s[i]==ch) b.pb(i);
		else b.pb(i+1);
	}
	printf("%d ",SZ(b));
	rep(i,0,SZ(b)) printf("%d ",b[i]+1); puts("");
	rep(i,0,n) if (i%2==0) printf("%d ",i+1); puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}