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
typedef long long ll;
typedef vector<ll> VI;
typedef basic_string<int> BI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=100050;
int _,n,cnt[26][26];
char s[N],t[N];

bool solve() {
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%s",t);
	rep(i,0,26) rep(j,0,26) cnt[i][j]=0;
	rep(i,0,n) {
		int x=(int)(s[i]-'a');
		int y=(int)(t[n-i-1]-'a');
		cnt[min(x,y)][max(x,y)]++;
	}
	bool ok=true;
	bool f=(n%2==1);
	rep(i,0,26) rep(j,0,26) {
		if (i==j) {
			if (f&&cnt[i][j]%2==1) f=false;
			else if (cnt[i][j]%2==1) ok=false;
		} else if (cnt[i][j]%2) ok=false;
	}
	return ok;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"YES":"NO");
	}
}