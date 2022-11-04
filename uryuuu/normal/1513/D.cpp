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
//#pragma comment(linker, "/STACK:36777216") //hdu 
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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
   
struct node
{
    int x,id;
}b[maxn];

ll a[maxn];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

int fa[maxn];

int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll p;
        cin>>p;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i].x;
            a[i]=b[i].x;
            b[i].id=i;
            fa[i]=i;
        }
        sort(b+1,b+n+1,cmp);
        
        ll ans=0ll;
        ll m=n-1;
        int w;
        int j;
        int fu,fv;
        for(int i=1;i<=n;i++)
        {
            w=b[i].x;
            if(w>=p)
            {
                break;
            }
            if(findx(b[i].id)!=b[i].id)
                continue;
            for(j=b[i].id+1;j<=n;j++)
            {
                if(a[j]<w||a[j]%w)
                    break;
                fu=findx(b[i].id);
                fv=findx(j);
                if(fu==fv)
                    continue;
                ans+=1ll*w;
                m--;
                if(a[fu]<a[fv])
                    swap(fu,fv);
                fa[fu]=fv;
            }
            
            for(j=b[i].id-1;j>=1;j--)
            {
                if(a[j]<w||a[j]%w)
                    break;
                fu=findx(b[i].id);
                fv=findx(j);
                if(fu==fv)
                    continue;
                ans+=1ll*w;
                m--;
                if(a[fu]<a[fv])
                    swap(fu,fv);
                fa[fu]=fv;
            }
            if(m==0)
                break;
        }
        
        ans=1ll*ans+1ll*m*p;
        cout<<ans<<endl;
    }
    
    return 0;
}