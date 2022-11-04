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
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[maxn];

vector<int>g[maxn];
struct nod
{
    int L,R;
}b[maxn];

ll num;
ll prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
void sushu()
{         // 
    num=0;        //num 
    memset(sf,true,sizeof(sf));
    sf[1] = false;
    sf[0] = false;  //1 0 
    for(int i = 2;i <= maxn; i ++)
    {          //1~maxn
        if(sf[i]) prime[++num] = i;      //
        for(int j = 1;j <= num;j ++)
        {       //num
            if(i * prime[j] > maxn) break; //
            sf[i * prime[j]] = false;      //...
            if(i % prime[j] == 0) break;   //
        }
    }
}

bool cmp(nod a,nod b)
{
    if(a.R==b.R)
    {
        return a.L<b.L;
    }
    return a.R<b.R;
}

int dp[maxn][21];
int d[maxn];


int main()
{
    sync;
    sushu();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    for(int i=1;i<=n;i++)
    {
        b[i].L=i;
        b[i].R=n+1;
    }
    
    int j;
    int p;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=num;j++)
        {
            p=prime[j];
            if(sf[a[i]])
            {
                g[a[i]].push_back(i);
                break;
            }
            if(a[i]<p)
                break;
            if(a[i]%p==0)
            {
                g[p].push_back(i);
                while(a[i]%p==0)
                {
                    a[i]/=p;
                }
            }
        }
    }
    int sz;
    for(int i=1;i<=num;i++)
    {
        p=prime[i];
        sz=g[p].size();
        for(j=0;j<sz-1;j++)
        {
            b[g[p][j]].R=min(b[g[p][j]].R,g[p][j+1]);
        }
    }
    
    
    
    for(int i=1;i<=n+1;i++)
    {
        d[i]=n+1;
    }
    
    for(int i=1;i<=n;i++)
    {
        d[b[i].L]=min(d[b[i].L],b[i].R);
    }
    
    for(int i=n;i>=1;i--)
    {
        d[i]=min(d[i],d[i+1]);
        dp[i][0]=d[i];
    }
    
    for(int i=0;i<=20;i++)
    {
        dp[n+1][i]=n+1;
    }
    
    for(int i=1;i<=20;i++)
    {
        for(j=1;j<=n;j++)
        {
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    
    
    int L,R;
    int ans=0;
    
    while(m--)
    {
        cin>>L>>R;
        ans=1;
        for(int i=20;i>=0;i--)
        {
            if(dp[L][i]<=R)
            {
                ans+=(1<<i);
                L=dp[L][i];
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}

/*
8 1
2 3 2 3 5 7 5 7
2 4
*/