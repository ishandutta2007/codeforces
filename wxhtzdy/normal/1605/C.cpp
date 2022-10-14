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

const int N=1010000;
int n,_,pref[N][3];
string s;

bool valid(int l,int r) {
	VI cnt(3);
	rep(i,0,3) cnt[i]=pref[r][i];
	rep(i,0,3) cnt[i]-=pref[l-1][i];
	if (cnt[0]>cnt[1]&&cnt[0]>cnt[2]) return true;
	else return false; 
}

void solve() {
	cin>>n>>s;
	rep(i,0,n) {
		pref[i+1][0]=pref[i][0]+(s[i]=='a');
		pref[i+1][1]=pref[i][1]+(s[i]=='b');
		pref[i+1][2]=pref[i][2]+(s[i]=='c');
	}
	VI pos;
	rep(i,0,n) if (s[i]=='a') pos.pb(i+1);
	int ans=n+1;
	rep(i,0,SZ(pos)) {
		rep(j,1,3) {
			if (i+j>=SZ(pos)) break;
			if (valid(pos[i],pos[i+j])) {
				ans=min(ans,pos[i+j]-pos[i]+1);
			}
		}
	}
	if (ans>n) cout<<"-1\n";
	else cout<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>_;
	for (;_;_--) {
		solve();
	}
}