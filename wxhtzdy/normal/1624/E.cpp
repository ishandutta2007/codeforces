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

int n,k,_;

void solve() {
	cin>>n>>k;
	vector<string> s(n+1);
	vector<tuple<int,int,int>> go2(100);
	vector<tuple<int,int,int>> go3(1000);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		rep(j,0,k-1) {
			int dd=(s[i][j]-'0')*10+s[i][j+1]-'0';
			go2[dd]={i,j+1,j+2};
			if (j+2<k) {
				dd=dd*10;
				dd+=(s[i][j+2]-'0');
				go3[dd]={i,j+1,j+3};
			}
		}
	}
	string t;
	cin>>t;
	deque<tuple<int,int,int>> dq;
	vector<bool> was(k+1,false);
	int suc=0;
	function<void(int)> dfs=[&](int pos) {
		if (suc) return;
		if (pos==k+1) {
			printf("%d\n",SZ(dq));
			for (auto pp:dq) {
				printf("%d %d %d\n",get<1>(pp),get<2>(pp),get<0>(pp));
			}
			printf("\n");
			suc=1;
			return;
		}
		if (was[pos]) return;
		was[pos]=1;
		if (pos==k) return;
		//int go2=-1,go3=-1;
		/*rep(i,1,n+1) {
			if (s[i][pos-1]==t[pos-1]&&s[i][pos]==t[pos]) go2=i;
			if (pos<k-1&&go2==i&&s[i][pos+1]==t[pos+1]) go3=i;
		}*/
		int dd=(t[pos-1]-'0')*10+t[pos]-'0';
		if (get<0>(go2[dd])!=0) {
			dq.pb(go2[dd]);
			dfs(pos+2);
			dq.pop_back();
		}
		if (pos+2<=k) {
			dd=dd*10;
			dd+=t[pos+1]-'0';
			if (get<0>(go3[dd])!=0) {
				dq.pb(go3[dd]);
				dfs(pos+3);
				dq.pop_back();
			}
		}
	};
	dfs(1);
	if (!suc) puts("-1");
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin>>_;
	for (;_;_--) {
		solve();
	}
}