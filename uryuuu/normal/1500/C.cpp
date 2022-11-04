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
#include <chrono>
#include <random>
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
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=2005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[maxn][maxn],b[maxn][maxn],va[maxn],vb[maxn],n,m,sum;
int d[maxn];
vector<int>g[maxn],ans;
bool fl[maxn];
 


int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>b[i][j];
    }
    ll base=1999925ll;
    for(int i=1;i<=n;i++)
    {
        a[i][m+1]=i;
        for(int j=1;j<=m;j++)
            va[i]=(1ll*base*va[i]+a[i][j])%Mod;
        for(int j=1;j<=m;j++)
            vb[i]=(1ll*base*vb[i]+b[i][j])%Mod;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(fl[j]==0&&va[j]==vb[i])
            {
                b[i][m+1]=j;
                fl[j]=1;
                break;
            }
        }
        if(b[i][m+1]==0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    
    mm(fl);
    for(int i=1;i<=m+1;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(b[j][i]>b[j+1][i])
            {
                g[j].push_back(i);
                d[i]++;
            }
        }
    }
    sum=0;
    queue<int>q;
    for(int i=1;i<=m+1;i++)
    {
        if(d[i]==0)
            q.push(i);
    }
    
    int u;
    while(q.size())
    {
        u=q.front();
        q.pop();
        ans.push_back(u);
        for(int i=1;i<n;i++)
        {
            if(fl[i]==0&&b[i][u]<b[i+1][u])
            {
                fl[i]=1;
                sum++;
                for(int v:g[i])
                {
                    d[v]--;
                    if(d[v]==0)
                        q.push(v);
                }
            }
        }
    }
    
    if(sum<n-1)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    reverse(ans.begin(),ans.end());
    int pos=-1;
    int sz=ans.size();
    for(int i=0;i<sz;i++)
    {
        if(ans[i]==m+1)
        {
            pos=i;
            break;
        }
    }
//    for(int v:ans)
//        cout<<v<<' ';
//    cout<<endl;
    cout<<sz-pos-1<<endl;
    for(int i=pos+1;i<sz;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    
    return 0;
}