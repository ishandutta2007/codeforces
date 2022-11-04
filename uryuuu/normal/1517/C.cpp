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
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[505][505];
int vis[505];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][i];
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=i-1;
    }
    
    int j;
    int x,y;
    int val;
    for(int i=1;i<=n;i++)
    {
        x=i;y=1;
        while(x<=n)
        {
            val=a[x][y];
            if(vis[val]<=0)
            {
                x++;
                y++;
                continue;
            }
            if(y>1&&a[x][y-1]==0)
            {
                a[x][y-1]=val;
                x++;
                y++;
                vis[val]--;
                continue;
            }
            if(x<n&&a[x+1][y]==0)
            {
                a[x+1][y]=val;
                x++;
                y++;
                vis[val]--;
                continue;
            }
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
           cout<<a[i][j]<<' ';
        cout<<endl;
    }
    
    return 0;
}