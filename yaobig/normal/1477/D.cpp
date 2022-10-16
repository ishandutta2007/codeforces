#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

set<int> e[maxn+5],S;
int mark[maxn+5];
int p[maxn+5],q[maxn+5];
vi leaves[maxn+5];

void dfs(int now,int fa)
{
    int son=-1;
    mark[now]=1;
    int last=0;
    while(1)
    {
        auto it=S.upper_bound(last);
        if(it==S.end()) break;
        int v=*it; last=v;
        if(e[now].find(v)==e[now].end())
        {
            S.erase(v);
            son=v;
            dfs(v,now);
        }
    }
    if(mark[now]==1)
    {
        if(fa!=0) mark[fa]=2,leaves[fa].pb(now);
        else leaves[son].pb(now);
    }
}

int main()
{
    int CAS; scanf("%d",&CAS); while(CAS--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,n) e[i].clear(); 
        rep(i,1,n) leaves[i].clear();
        S.clear();
        rep(i,1,n) S.insert(i); 
        rep(i,1,n) mark[i]=0;
        int tot=0;
        rep(i,1,m)
        {
            int x,y; scanf("%d%d",&x,&y);
            e[x].insert(y);
            e[y].insert(x);
        }
        rep(i,1,n) if(mark[i]==0)
        {
            if((int)e[i].size()==n-1) p[i]=q[i]=++tot;
            else {S.erase(i); dfs(i,0);}
        }
        rep(i,1,n) if(mark[i]==2)
        {
            p[i]=++tot;
            for(auto j: leaves[i]) p[j]=++tot;
            q[i]=tot;
            for(auto j: leaves[i]) q[j]=p[j]-1;
        }
        rep(i,1,n) printf("%d%c",p[i]," \n"[i==n]);
        rep(i,1,n) printf("%d%c",q[i]," \n"[i==n]);
    }
    return 0;
}