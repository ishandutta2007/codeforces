#ifdef ONLINE_JUDGE
    #pragma GCC optimize("O3")
#endif // ONLINE_JUDGE

#include <bits/stdc++.h>

#define int long long

//#define PRT(x) cout<<#x<<" = "<<x<<"\n"

using namespace std;

const int N=5010;

int p[N],c[N],k[N];
bool del[N];
vector<int> g[N];
int f[N];
bool used[N][2];
int ans[N];

bool dfs(int v,bool num)
{
//    PRT(v);
//    PRT(num);
    if(used[v][num])
        return false;
    used[v][num]=true;
    if(num)
    {
        for(int to:g[v])
        {
            bool res=dfs(to,false);
            if(res)
                return f[to]=v,
                       true;
        }
        return false;
    }
    else
    {
        if(f[v]==-1)
            return true;
        return dfs(f[v],true);
    }
}

signed main()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
//        #define name ""
//        freopen(name".in","r",stdin);
//        freopen(name".out","w",stdout);
//        #undef name
    #endif // ONLINE_JUDGE

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    int d;
    cin>>d;
    for(int i=1;i<=d;i++)
        cin>>k[i],
        del[k[i]]=true;
    for(int i=1;i<=n;i++)
        if(!del[i])
            g[p[i]].push_back(c[i]);
    memset(f,255,sizeof(f));
    int res=0;
    while(true)
    {
        memset(used,0,sizeof(used));
        if(dfs(res,true))
            res++;
        else
            break;
    }
//    PRT(res);
    ans[d]=res;
    for(int i=d;i>1;i--)
    {
//        PRT(i);
//        PRT(p[k[i]]);
//        PRT(c[k[i]]);
        g[p[k[i]]].push_back(c[k[i]]);
        while(true)
        {
            memset(used,0,sizeof(used));
            if(dfs(res,true))
                res++;
            else
                break;
        }
//        PRT(res);
        ans[i-1]=res;
    }
    for(int i=1;i<=d;i++)
        cout<<ans[i]<<"\n";
}
/**

6 8
0 1 2 3 4 11
4 8 6 2 4 4
6
6 5 4 3 2 1

*/