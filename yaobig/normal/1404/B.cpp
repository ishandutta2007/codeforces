#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int dep[maxn+5];
int fur;

void dfs(int now,int fa)
{
    if(dep[fur]<dep[now]) fur=now;
    for(auto v: e[now]) if(v!=fa)
    {
        dep[v]=dep[now]+1;
        dfs(v,now);
    }
}
int main()
{
    int cas; scanf("%d",&cas);
    while(cas--)
    {
        int n,a,b,da,db; scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1)
        {
            int x,y; scanf("%d%d",&x,&y);
            e[x].pb(y);
            e[y].pb(x);
        }
        if(2*da>=db) {puts("Alice"); continue;}
        dep[a]=0; fur=a;
        dfs(a,0);
        if(dep[b]<=da) {puts("Alice"); continue;}
        dep[fur]=0;
        dfs(fur,0);
        if(dep[fur]<=2*da) puts("Alice");
        else puts("Bob");
    }
    return 0;
}