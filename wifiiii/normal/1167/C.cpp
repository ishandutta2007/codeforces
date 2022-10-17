
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

const int maxn = 5e5+5;
int par[maxn],sz[maxn];
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int find(int a)
{
    return par[a]==a?a:par[a]=find(par[a]);
}
void Union(int a,int b)
{
    int x=find(a),y=find(b);
    if(x==y) return;
    if(sz[x]<sz[y])
    {
        par[x]=y;
        sz[y]+=sz[x];
    }
    else
    {
        par[y]=x;
        sz[x]+=sz[y];
    }
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i) par[i]=i,sz[i]=1;
    rep(i,m)
    {
        int t = read();
        if(!t)continue;
        int f = read();
        for(int i=1;i<t;++i)
        {
            int tmp = read();
            Union(f,tmp);
        }
    }
    rep(i,n) printf("%d ",sz[find(i)]);
    printf("\n");
}