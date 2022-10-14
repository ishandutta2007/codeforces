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
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1005;
int n,m,a[N][N];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,0,n) rep(j,0,m) scanf("%d",&a[i][j]);
    int ans=0;
    rep(i,0,n) {
        bool f=false;
        rep(j,0,m) {
            if (a[i][j]) f=true;
            else ans+=f;
        }
    }
    rep(i,0,n) {
        bool f=false;
        per(j,0,m) {
            if (a[i][j]) f=true;
            else ans+=f;
        }
    }
    rep(j,0,m) {
        bool f=false;
        rep(i,0,n) {
            if (a[i][j]) f=true;
            else ans+=f;
        }
    }
    rep(j,0,m) {
        bool f=false;
        per(i,0,n) {
            if (a[i][j]) f=true;
            else ans+=f;
        }
    }
    printf("%d",ans);
}