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

const int N=200050;
int n,k,_;
char s[N];
bool vv[N];
VI pos[26];

void solve() {
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,0,26) pos[i].clear(),vv[i]=false;
	rep(i,1,n+1) pos[s[i]-'a'].pb(i);
	rep(i,1,n+1) {
		if (s[i]=='a') continue;
		while (s[i]>'a') {
			if (vv[s[i]-'a']) s[i]--;
			else if (k>0) vv[s[i]-'a']=true,k--;
			else break;
		}
	}
	printf("%s\n",s+1);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}