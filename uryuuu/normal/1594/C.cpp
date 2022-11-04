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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
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
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

vector<int>g[maxn];
int vis[maxn];
string s;
char c;

int main()
{
    sync;
    int j;
    for(int i=1;i<maxn;i++)
    {
        for(j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                g[i].push_back(j);
                g[i].push_back(i/j);
            }
        }
    }
   
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        s="";
        cin>>n>>c>>s;
        for(int i=1;i<=n;i++)
            vis[i]=0;
        int f=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]!=c)
            {
                for(int v:g[i])
                {
                    vis[v]=1;
                }
                f=1;
            }
        }
        if(f==0)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                ans=i;
                break;
            }
        }
        if(ans)
        {
            cout<<1<<endl;
            cout<<ans<<endl;
            continue;
        }
        cout<<2<<endl;
        cout<<n<<' ';
        for(int i=1;i<=n;i++)
        {
            if(n%i)
            {
                cout<<i<<endl;
                break;
            }
        }
        
    }
    return 0;
}