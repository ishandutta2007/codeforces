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
//#include<unordered_map>
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
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int siz[1010];
int x;
vector<int>g[1100];

void dfs(int u,int fa)
{
    siz[u]=1;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}

 
int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
        }
        int u,v;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int sz=g[x].size();
        if(sz<=1)
        {
            cout<<"Ayush"<<endl;
            continue;
        }
//        dfs(x,0);
        if((n-2)%2==0)
            cout<<"Ayush"<<endl;
        else
            cout<<"Ashish"<<endl;
                
    }
    
    
    return 0;
}







//4 1
//1 3
//2 1
//4 1