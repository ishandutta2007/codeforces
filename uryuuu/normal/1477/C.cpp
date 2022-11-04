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
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;


struct node
{
    int x,y;
    int id;
}a[maxn];

int vis[maxn];

ll dis(int u,int v)
{
    return 1ll*(a[u].x-a[v].x)*(a[u].x-a[v].x)+1ll*(a[u].y-a[v].y)*(a[u].y-a[v].y);
}

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    cout<<1<<' ';
    int id=1;
    vis[1]=1;
    for(int i=1;i<n;i++)
    {
        ll mx=-1;
        int pos=0;
        for(int j=1;j<=n;j++)
        {
            if(vis[j])
                continue;
            if(dis(id,j)>mx)
            {
                mx=dis(id,j);
                pos=j;
            }
        }
        id=pos;
        vis[id]=1;
        cout<<id<<' ';
    }
    cout<<endl;
    
    
    return 0;
}