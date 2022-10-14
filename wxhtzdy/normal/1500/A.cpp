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

const int N=201000;
int n,a[N];
PII pos[5010000];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,n) rep(j,i+1,n) {
		int s=a[i]+a[j];
		if (pos[s]==mp(0,0)) pos[s]=mp(i,j);
		else if (pos[s].fi!=i&&pos[s].se!=i&&pos[s].fi!=j&&pos[s].se!=j) {
			printf("YES\n%d %d %d %d\n",i+1,j+1,pos[s].fi+1,pos[s].se+1);
			return 0;
		}
	}
	puts("NO");
}