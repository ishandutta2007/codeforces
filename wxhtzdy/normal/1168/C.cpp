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

const int N=301000;
int n,q,a[N],lst[30],nxt[N][30];
int main() {
	scanf("%d%d",&n,&q);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,30) lst[i]=-1;
	rep(i,0,n) rep(j,0,30) nxt[i][j]=n;
	per(i,0,n) rep(j,0,30) if (a[i]&(1<<j)) {
		if (lst[j]!=-1) rep(x,0,30) nxt[i][x]=min(nxt[i][x],nxt[lst[j]][x]);
		nxt[i][j]=i; lst[j]=i;
	}
	while (q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		--x; --y;
		bool ok=0;
		rep(j,0,30) if ((a[y]&(1<<j))&&nxt[x][j]<=y) ok=1;
		puts(ok?"Shi":"Fou");
	}
}