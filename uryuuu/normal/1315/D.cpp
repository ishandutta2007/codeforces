#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;


ll fa[maxn];
ll b[maxn];
ll zx[maxn];
struct node
{
    ll s,t;
}a[maxn];

ll findx(ll x)
{
    if(x==fa[x])
        return x;
    return fa[x]=findx(fa[x]);
}

void jihe(ll x,ll y)
{
    x=findx(x);
    y=findx(y);
    if(x!=y)
        fa[x]=y;
}


bool cmp(node a,node b)
{
    return a.t>b.t;
}

map<ll,ll>mp;

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].s;
    for(int i=1;i<=n;i++)
        cin>>a[i].t;

    sort(a+1,a+1+n,cmp);
    ll x;
    ll pos,id;
    ll L,R;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        x=a[i].s;
        if(mp[x])
        {
//            cout<<x<<a[i].t<<endl;
            id=findx(mp[x]);
            pos=zx[id];
            sum+=1ll*(pos-x)*a[i].t;
            mp[pos]=i;
            jihe(i,id);
            id=findx(i);
            x=pos;
            zx[id]=x+1;
        }
        else
        {
            mp[x]=i;
            zx[findx(i)]=x+1;
            if(x-1>0&&mp[x-1])
            {
                id=findx(mp[x-1]);
                jihe(i,id);
                id=findx(i);
                zx[id]=x+1;
            }
        }
        if(mp[x+1])
        {
            L=findx(mp[x+1]);
            R=zx[L];
            jihe(L,i);
            zx[findx(i)]=R;
        }
    }
    cout<<sum<<endl;
    return 0;
}