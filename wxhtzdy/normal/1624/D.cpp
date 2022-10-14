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
int _,n,k,cc[26];
char s[N];

bool check(int x) {
	int tot=0,c2=0,c1=0;
	rep(i,0,26) {
		c2+=cc[i]/2;
		c1+=cc[i]%2;
	}
	if (x%2==0) {
		int tot=c2/(x/2);
		return tot>=k;
	} else {
		int mn=min(c1,c2/(x/2));
		int tot=mn;
		c1-=mn;
		c2-=mn*(x/2);
		c2*=2;
		tot+=c2/x;
		return tot>=k;	
	}
}

void solve() {
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	rep(i,0,26) cc[i]=0;
	rep(i,0,n) cc[s[i]-'a']++;
	int l=2,r=n,ans=1;
	while (l<=r) {
		int md=l+r>>1;
		if (check(md)) l=md+1,ans=md; else r=md-1;
	}
	printf("%d\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}