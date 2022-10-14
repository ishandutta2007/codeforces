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
typedef long long ll;
typedef basic_string<int> BI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=200050;
char s[N],ans[N];
int _,mark[N];

void solve() {
	scanf("%s",s);
	int n=strlen(s);
	int k=-1,m=0;
	rep(i,0,n) mark[i]=0;
	for (char c='0';c<='9';c++) {
		rep(i,0,k) if (!mark[i]&&s[i]+1==c) {
			mark[i]=1;
			ans[m++]=c;
		}
		rep(i,k+1,n) if (!mark[i]&&s[i]==c) {
			mark[i]=1;
			k=i;
			ans[m++]=c;
		}
	}
	rep(i,0,n) if (!mark[i]) ans[m++]='9';
	rep(i,0,m) printf("%c",ans[i]); puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}