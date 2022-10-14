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


int x1,p1,x2,p2,_;

int cc(int x) {
	int cnt=0;
	while (x) {
		cnt++; x/=10;
	}
	return cnt;
}

void solve() {
	scanf("%d%d",&x1,&p1);
	scanf("%d%d",&x2,&p2);
	while (cc(x1)<cc(x2)&&p1) {
		x1*=10;
		p1--;
	}
	while (cc(x1)>cc(x2)&&p2) {
		x2*=10;
		p2--;
	}
	int len1=cc(x1);
	int len2=cc(x2);
	if (len1+p1<len2+p2) {
		puts("<");
	} else if (len1+p1>len2+p2) {
		puts(">");
	} else {
		if (x1==x2) puts("=");
		else if (x1<x2) puts("<");
		else puts(">");
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}