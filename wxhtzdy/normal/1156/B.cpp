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

const int N=105;
int _;
string s;

bool valid(string s) {
	int n=SZ(s);
	rep(i,0,n-1) if ((int)abs(s[i]-s[i+1])==1) return false;
	return true;
}

void solve() {
	cin>>s;
	int n=SZ(s);
	VI v[2];
	rep(i,0,n) {
		int c=(int)(s[i]-'a');
		v[c%2].pb(i);
	}
	sort(all(v[0]),[&](int i,int j) { return s[i]>s[j]; });
	sort(all(v[1]),[&](int i,int j) { return s[i]>s[j]; });
	string ans="";
	rep(j,0,2) rep(i,0,SZ(v[j])) ans+=s[v[j][i]];
	if (!valid(ans)) {
		ans="";
		per(j,0,2) rep(i,0,SZ(v[j])) ans+=s[v[j][i]];
		if (!valid(ans)) puts("No answer");
		else {
			rep(i,0,SZ(ans)) printf("%c",ans[i]); puts("");
		}
	}
	else {
		rep(i,0,SZ(ans)) printf("%c",ans[i]); puts("");
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}