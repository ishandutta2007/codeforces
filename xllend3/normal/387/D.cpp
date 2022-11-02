#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= (int)n; ++i)
#define dep(i,a,n) for (int i = a; i >= (int)n; --i)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define clr(a,b) memset(a,sizeof(a),b);
#define inf 0x7fffffff
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
inline void read(int &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int l,m,n,t,b[1111],c[1111],tot,ans=0x7fffffff,used[1111],to[1111],d[1111];
vector<int>a[1111];
int find(int x)
{
    used[x]=1;
    rep(_,0,a[x].size()-1)
    {
        int i=a[x][_];
        if(i==l)continue;if(!to[i]||(!used[to[i]]&&find(to[i]))){to[i]=x;return 1;}
    }return 0;
}
void findpath(int x)
{
    tot=0;
    memset(to,0,sizeof(to));
    rep(i,1,n){if(i==x)continue;memset(used,0,sizeof(used));if(find(i))++tot;
    }
}
int main()
{
    scanf("%d%d",&n,&m);rep(i,1,m){scanf("%d%d",&l,&t),a[l].pb(t),b[l]++,c[t]++; 
    if(l==t)d[l]=1;
}
    rep(_,1,n){
        l=_;findpath(_);
        //printf("%d %d\n",_,tot);
        //ans=min(ans,tot+2*n-b[_]-c[_]+m-1);
        ans=min(ans,(m-b[_]-c[_]+(d[l]?1:0)-tot)+(n-1-tot)+2*n-b[_]-c[_]-1+(d[l]?1:0));
        //printf("%d %d %d %d %d\n",_,ans,tot,b[_],c[_]);
        //printf("%d %d\n",_,tot);
        //printf("%d %d\n",_,ans);
    }printf("%d\n",ans);
    return 0;
}