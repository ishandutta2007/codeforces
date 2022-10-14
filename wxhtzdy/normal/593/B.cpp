#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef long double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,x1,x2,k,b;
vector<pair<db,db>> sg;

int main() {
    scanf("%d%d%d",&n,&x1,&x2);
    rep(i,0,n) {
        scanf("%d%d",&k,&b);
        db y1=(x1+0.00000001)*k+b;
        db y2=(x2-0.00000001)*k+b;
        sg.pb(mp(y1,y2));
    }
    sort(all(sg));
    db mx=-1e18;
    rep(i,0,SZ(sg)) {
        if (i>0&&sg[i-1].fi==sg[i].fi) {
            puts("YES");
            return 0;
        }
        if (mx>=sg[i].se) {
            puts("YES");
            return 0;
        }
        mx=max(mx,sg[i].se);
    }
    puts("NO");
}