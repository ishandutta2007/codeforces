#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
db ans;

void dfs(int now,int fa,int dep)
{
    ans+=1.0/dep;
    for(auto v: e[now]) if(v!=fa) dfs(v,now,dep+1);
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0,1);
    printf("%.9f\n",ans);
    return 0;
}