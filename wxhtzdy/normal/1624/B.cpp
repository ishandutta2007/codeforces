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

int _,a,b,c;

bool check(int a1,int a2) {
	if (a1>a2) return false;
	if (a2%a1!=0) return false;
	return true;
}

void solve() {
	scanf("%d%d%d",&a,&b,&c);
	if (a==b&&b==c) {
		puts("YES");
		return;
	}
	int suc=0,d=c-a;
	if (abs(d)%2==0&&check(b,a+d/2)) suc=1;
	d=b-a;
	if (check(c,b+d)) suc=1;
	d=c-b;
	if (check(a,b-d)) suc=1;
	puts(suc?"YES":"NO");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}