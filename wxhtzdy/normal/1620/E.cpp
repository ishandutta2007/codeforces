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

const int N=505000;
int n,q,ans[N];
VI pos[N];

int main() {
	scanf("%d",&q);
	int sz=0;
	rep(i,1,q+1) {
		int t;
		scanf("%d",&t);
		if (t==1) {
			int x;
			scanf("%d",&x);
			pos[x].pb(sz++);
		} else {
			int x,y;
			scanf("%d%d",&x,&y);
			if (x==y) continue;
			if (SZ(pos[x])>SZ(pos[y])) swap(pos[x],pos[y]);
			for (int i:pos[x]) pos[y].pb(i);
			pos[x].clear();
		}
	}
	rep(i,1,N) for (int x:pos[i]) ans[x]=i;
	rep(i,0,sz) printf("%d ",ans[i]);
}