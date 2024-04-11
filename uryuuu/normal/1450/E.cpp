#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


ll dis[205][205];
vector<int>g[205];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    int u,v,op;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>op;
        dis[u][v]=1;
        g[u].push_back(v);
        if(op==0)
        {
            dis[v][u]=1;
        }
        else
        {
            dis[v][u]=-1;
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    
    
    ll mx=-1,st=1;
    for(int i=1;i<=n;i++)
    {
        if(dis[i][i]!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        for(int j=1;j<=n;j++)
        {
            if(dis[i][j]>mx)
            {
                mx=dis[i][j];
                st=i;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int v:g[i])
        {
            if(dis[st][i]==dis[st][v])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<mx<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<dis[st][i]<<' ';
    }
    cout<<endl;
    return 0;
}