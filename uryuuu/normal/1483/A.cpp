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
//#include <chrono>
//#include <random>
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
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

vector<int>g[maxn],fg[maxn];
int vis[maxn];
int ans[maxn];

int main()
{
    sync;
    int t;
    int n;
    int m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            fg[i].clear();
        }
        int k,x;
        for(int i=1;i<=m;i++)
        {
            g[i].clear();
            ans[i]=0;
            cin>>k;
            while(k--)
            {
                cin>>x;
                vis[x]++;
                g[i].push_back(x);
                fg[x].push_back(i);
            }
        }
        int lmt=(m+1)/2;
        int mx=0,id=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]>mx)
            {
                mx=vis[i];
                id=i;
            }
        }
        for(int u:fg[id])
        {
            if(mx<=lmt)
                break;
            for(int v:g[u])
            {
                if(v!=id)
                {
                    mx--;
                    ans[u]=v;
                    break;
                }
            }
        }
        if(mx>lmt)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int u:fg[id])
        {
            if(ans[u]==0)
            {
                ans[u]=id;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(ans[i]==0)
                ans[i]=g[i][0];
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        
    }
    
    return 0;
}