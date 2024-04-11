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

const int N=505000;
int n,m,l[N],r[N],st[N][20];
VI qs[N];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,0,n) scanf("%d%d",l+i,r+i),qs[l[i]].pb(r[i]);
    rep(i,0,N) rep(j,0,20) st[i][j]=-1;
    rep(i,0,N) {
        if (i) st[i][0]=st[i-1][0];
        for (auto x:qs[i]) st[i][0]=max(st[i][0],x);
        if (st[i][0]<=i) st[i][0]=-1;
    }
    rep(j,1,20) rep(i,0,N) if (st[i][j-1]!=-1) {
        st[i][j]=st[st[i][j-1]][j-1];
        assert(st[i][j]==-1||st[i][j]>=i);
    }
    while (m--) {
        int x,y;
        scanf("%d%d",&x,&y);
        int ans=0;
        per(i,0,20) {
            if (st[x][i]!=-1&&st[x][i]<=y) {
                x=st[x][i];
                ans+=(1<<i);
            }
        }
        if (x<y&&st[x][0]<y) puts("-1");
        else printf("%d\n",ans+(x<y));
    }
}