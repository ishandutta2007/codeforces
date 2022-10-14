//just bored
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
int _,c[3][2*N],n;
char s[N];
void init(int i,int _n) {
	for(int x=0;x<=2*_n+5;x++) c[i][x]=0;
}
void modify(int i,int x,int y) {
	for(;x<=2*n+5;x+=x&-x) c[i][x]+=y;
}
int query(int i,int x) {
	int r=0;
	for(;x>0;x-=x&-x) r+=c[i][x];
	return r;
}

void solve() {
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=0;i<3;i++) init(i,n);
	modify((n+1)%3,n+1,1);
	ll ans=0; int bal=n+1;
	for(int i=1;i<=n;i++) {
		if(s[i]=='-') bal++;
		if(s[i]=='+') bal--;
		int md=((bal%3)+3)%3;
		ans+=query(md,bal);
		modify(md,bal,1);
	}
	printf("%lld\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}