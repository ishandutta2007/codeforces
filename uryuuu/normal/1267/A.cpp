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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

struct node
{
    ll x,t;
    bool tag;
}a[maxn];

multiset<ll>st;

bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.tag>b.tag;
    return a.x<b.x;
}

int main()
{
    sync;
    int n;
    cin>>n;
    int cnt=0;
    ll l,r,t;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r>>t;
        a[++cnt].x=l+t;
        a[cnt].t=t;
        a[cnt].tag=1;
        a[++cnt].x=r;
        a[cnt].t=t;
        a[cnt].tag=0;
    }
    ll ans=0,s,now=0;
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(st.size())
        {
            s=(a[i].x-now)/(*st.begin());
            ans+=s;
            now+=s*(*st.begin());
        }
        if(a[i].tag)
        {
            if(now<=a[i].x-a[i].t)
            {
                now=a[i].x;
                ans++;
            }
            st.insert(a[i].t);
        }
        else
        {
            st.erase(st.find(a[i].t));
        }
    }
    
    cout<<ans<<endl;
    return 0;
}