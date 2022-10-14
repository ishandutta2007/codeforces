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

const int N=1010000;
int n,a[N],t;
PII st[N];
ll s[N];
db sval[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	rep(i,1,n+1) {
		db val=a[i];
		PII pr=mp(i,i);
		while (t>0&&sval[t-1]>val) {
			--t;
			val=1.*(s[i]-s[st[t].fi-1])/(i-st[t].fi+1);
			pr=mp(st[t].fi,i);
		}
		sval[t]=val;
		st[t]=pr;
		t++;
	}
	rep(i,0,t) rep(j,st[i].fi,st[i].se+1) printf("%.10f\n",sval[i]);
}