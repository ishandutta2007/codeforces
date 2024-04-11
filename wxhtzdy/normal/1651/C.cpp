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
int _,n,a[N],b[N];
int main() {
    for (scanf("%d",&_);_;_--) {
        scanf("%d",&n);
        rep(i,0,n) {
            scanf("%d",&a[i]);
        }
        rep(i,0,n) {
            scanf("%d",&b[i]);
        }
        const ll inf=1e18;
        const int inf2=2e9;
        vector<int> dis(16,inf2);
        for (int x:{0,n-1}) for (int y:{0,n-1}) {
            int vx=(x==0?1:2),vy=(y==0?4:8);
            dis[vx|vy]=abs(a[x]-b[y]);
        }
        rep(i,0,n) {
            dis[1]=min(dis[1],abs(a[0]-b[i]));
            dis[2]=min(dis[2],abs(a[n-1]-b[i]));
            dis[4]=min(dis[4],abs(a[i]-b[0]));
            dis[8]=min(dis[8],abs(a[i]-b[n-1]));
        }
        vector<ll> ans(16,inf);
        ans[0]=0;
        rep(i,0,16) rep(j,0,16) ans[i|j]=min(ans[i|j],ans[i]+dis[j]);
        printf("%lld\n",ans[15]);
    }
}