#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[12][maxn+5],mx[maxn+5];
int s[1<<12];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(r,0,n-1) rep(c,0,m-1) scanf("%d",&a[r][c]);
        rep(c,0,m-1) 
        {
            mx[c]=0;
            rep(r,0,n-1) chmax(mx[c],a[r][c]);
        }
        vi id;
        rep(c,0,m-1) id.pb(c);
        sort(id.begin(),id.end(),[](int a,int b){return mx[a]>mx[b];});
        if(m>n) id.resize(n);
        int N=1<<n;
        vi dp(N,0);
        for(auto c: id)
        {
            vi ndp(N,0);
            rep(i,1,n)
            {
                vi tmp=dp;
                rep(r,0,n-1) rep(msk,0,N-1) if(msk&(1<<r)) chmax(tmp[msk],tmp[msk^(1<<r)]+a[r][c]);
                rep(msk,0,N-1) chmax(ndp[msk],tmp[msk]);
                swap(a[0][c],a[n-1][c]);
                rep(r,0,n-3) swap(a[r][c],a[r+1][c]);
            }
            dp=ndp;
        }
        printf("%d\n",dp[N-1]);
    }
    return 0;
}