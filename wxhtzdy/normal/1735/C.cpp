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

const int N=100050;
char s[N];
int n,_,prv[50],f[50],was[50];

int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }

void solve() {
	scanf("%d%s",&n,s);
	rep(i,0,26) f[i]=i,prv[i]=-1,was[i]=0;
	int cc=0;
	rep(i,0,n) {
		int c=(int)(s[i]-'a');
		if (prv[c]==-1) {
			rep(j,0,26) if (c!=j&&!was[j]&&(cc==25||find(c)!=find(j))) {
				was[j]=1;
				prv[c]=j;
				f[find(c)]=find(j);
				cc++;
				break;
			}
		}
		printf("%c",(char)('a'+prv[c]));
	}
	puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}