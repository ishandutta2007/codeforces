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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn=100005;
const ll Mod=1000000007;


int n,q,num_edge;
int f[maxn],depth[maxn];
//fdepth
int st[30][maxn];
//i2^ij
//
int first[maxn],Next[2*maxn],v[2*maxn];
//v,Next
//first
void road(int x,int y) //xy
{
    v[++num_edge]=y;//y
    Next[num_edge]=first[x];//
    first[x]=num_edge;//
}
void dfs(int son,int father)
{
    f[son]=father;//son
    //son
    for(int i = first[son]; i!=-1; i=Next[i])
    {
        int to = v[i];//
        if(to==father)continue;//
        depth[to]=depth[son]+1;
        dfs(to,son);
    }
}
int get_lca(int x,int y)
{
    if(depth[x]<depth[y])swap(x,y);//xy
    //xy
    for(int i = 20; i >= 0; i--)
        if(depth[st[i][x]]>=depth[y])
            x=st[i][x];
    //yxy
    if(x==y)return x;
    //xy
    for(int i = 20; i >= 0; i--)
        if(st[i][x]!=st[i][y])
        {
            x=st[i][x];
            y=st[i][y];
        }
    //
    return f[x];
}

int d[10];

int jl(int x,int y)
{
    int father = get_lca(x,y);
    //xy
    return (depth[x]+depth[y]-2*depth[father]);
}


int main()
{
    sync;
    int x,y;
    cin>>n;
    memset(first,-1,sizeof(first));
    num_edge=0;
    //
    for(int i = 1; i < n; i++)
    {
        cin>>x>>y;
        road(x,y);
        road(y,x);
    }
    //depth
    depth[1]=1;//1
    dfs(1,0);//depth
    //st
    //2^0
    for(int i = 1; i <= n; i++)
        st[0][i]=f[i];
    //j2^ist[i][j]
    //2^(i-1)+2^(i-1)=2^i
    //j2^(i-1)2^(i-1)st[i][j]
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= n; j++)
            st[i][j]=st[i-1][st[i-1][j]];
    //q
    cin>>q;
    while(q--)
    {
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        d[0]=jl(a,b);
        d[1]=jl(a,x)+jl(y,b)+1;
        d[2]=jl(a,y)+jl(x,b)+1;
        int f=0;
        for(int i=0;i<=2;i++)
        {
            if(d[i]<=k&&(k-d[i])%2==0)
            {
                f=1;
                break;
            }
        }
        if(f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
 
    return 0;
}