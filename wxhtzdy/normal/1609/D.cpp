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

const int N=1010;
int n,m,x[N],y[N],f[N],sz[N];

int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}

int main() {
   	scanf("%d%d",&n,&m);
   	rep(i,0,m) scanf("%d%d",x+i,y+i);
   	rep(i,1,n+1) f[i]=i,sz[i]=1;
   	int kk=1;
   	rep(i,0,m) {
   		x[i]=find(x[i]);
   		y[i]=find(y[i]);
   		if (x[i]!=y[i]) {
   			sz[x[i]]+=sz[y[i]];
   			f[y[i]]=x[i];
   		} else kk++;
   		VI v;
   		rep(i,1,n+1) if (find(i)==i) v.pb(sz[i]);
   		sort(all(v));
   		reverse(all(v));
   		int ans=0;
   		rep(i,0,kk) ans+=v[i];
   		printf("%d\n",ans-1);
   	}
    return 0;
}