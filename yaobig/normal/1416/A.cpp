#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi idx[maxn+5];
int ans[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) idx[i].clear();
        rep(i,1,n) idx[i].pb(0);
        rep(i,1,n)
        {
            int x; scanf("%d",&x);
            idx[x].pb(i);
        }
        rep(i,1,n) idx[i].pb(n+1);
        rep(k,1,n) ans[k]=inf;
        per(i,1,n)
        {
            int d=0,l=idx[i].size();
            rep(j,1,l-1) d=max(d,idx[i][j]-idx[i][j-1]);
            ans[d]=i;
        }
        rep(k,2,n) ans[k]=min(ans[k-1],ans[k]);
        rep(i,1,n) if(ans[i]==inf) ans[i]=-1;
        rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}