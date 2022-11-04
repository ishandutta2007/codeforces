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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[maxn];
int b[maxn];

int fa[maxn];

int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}
int siz[maxn];



int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            b[i]=a[i];
            siz[i]=1;
            fa[i]=i;
        }
        sort(b+1,b+n+1);
        int fl=0;
        for(int i=2;i<=n;i++)
        {
            if(b[i]==b[i-1])
                fl=1;
        }
        if(fl)
        {
            cout<<"YES"<<endl;
            continue;
        }
        int u,v,fu,fv;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==i)
                continue;
            u=i;
            v=a[i];
            fu=findx(u);
            fv=findx(v);
            if(fu==fv)
                continue;
            fa[fu]=fv;
            siz[fv]+=siz[fu];
            siz[fu]=0;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            fu=findx(i);
        }
        for(int i=1;i<=n;i++)
        {
            if(siz[i]>0&&siz[i]%2==0)
                sum++;
        }
        if(sum%2==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}