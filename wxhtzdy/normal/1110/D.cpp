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

const int N=1050000;
int n,m,cc[N],dp[N][3][3];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		int x;
		scanf("%d",&x);
		cc[x]++;
	}
	rep(i,1,N-5) {
		rep(x,0,3) rep(y,0,3) rep(z,0,3) {
			if (cc[i]<x+y+z) continue;
			dp[i+1][y][z]=max(dp[i+1][y][z],dp[i][x][y]+z+(cc[i]-x-y-z)/3);
		}
	}
	printf("%d",dp[N-5][0][0]);
}