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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[5][maxn];
ll dp[maxn];
int n[5];
int m;
vector<int>g[maxn];
void init()
{
    for(int i=1;i<=200002;i++)
    {
        g[i].clear();
    }
}

int b[maxn];

int id;

bool cmp(int u,int v)
{
    return a[id][u]<a[id][v];
}

unordered_map<int,int>mp;

int main()
{
    sync;
    for(int i=1;i<=4;i++)
        cin>>n[i];
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=n[i];j++)
            cin>>a[i][j];
    }
    
    ll mn;
    int L;
   
    for(id=1;id<=3;id++)
    {
        for(int i=id;i<=n[id];i++)
        {
            dp[i]=a[id][i];
        }
        init();
        cin>>m;
        int u,v;
        for(int i=1;i<=m;i++)
        {
            cin>>v>>u;
            g[u].push_back(v);
        }
        for(int i=1;i<=n[id];i++)
            b[i]=i;
        sort(b+1,b+n[id]+1,cmp);
        for(int i=1;i<=n[id+1];i++)
        {
            mp.clear();
            for(int v:g[i])
            {
                mp[v]++;
            }
            mn=1e12;
            for(L=1;L<=n[id];L++)
            {
                if(mp[b[L]]==0)
                {
                    mn=a[id][b[L]];
                    break;
                }
            }
            a[id+1][i]+=mn;
        }
    }
    
    mn=1e12;
    for(int i=1;i<=n[4];i++)
    {
        mn=min(mn,a[4][i]);
    }
    if(mn==1e12)
        cout<<-1<<endl;
    else
        cout<<mn<<endl;
    
    return 0;
}