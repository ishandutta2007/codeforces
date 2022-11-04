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
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int n,q;
int a[maxn];


set<int>st;

ll b[maxn];
void Upd(int x,ll val)
{
//    cout<<"UPD"<<' '<<x<<' '<<val<<endl;
    while(x<maxn)
    {
        b[x]+=val;
        x+=lb(x);
    }
}

ll qry(int x)
{
    ll res=0;
    while(x)
    {
        res+=b[x];
        x-=lb(x);
    }
    return res;
}


ll pw[maxn];
int len;
void upd(int x,int y)
{
    int L,R;
    auto Lt=st.lower_bound(x);
    Lt--;
    L=*Lt+1;
    auto Rt=st.lower_bound(x);
    R=*Rt;
    len=R-L+1;
    Upd(R,-pw[len]);
    st.erase(Rt);
    
    int pos;
    
    a[x]=y;
    if(L<x)
    {
        if(a[x]<a[x-1])
        {
            Upd(x-1,pw[x-L]);
            st.insert(x-1);
            L=x;
        }
    }
    else
    {
        if(x>1&&a[x]>=a[x-1])
        {
            auto Lt=st.lower_bound(x);
            Lt--;
            Lt--;
            L=*Lt+1;
            Lt++;
            st.erase(Lt);
            Upd(x-1,-pw[x-1-L+1]);
        }
    }
    
    if(R>x)
    {
        if(a[x]>a[x+1])
        {
            Upd(R,pw[R-x]);
            st.insert(R);
            R=x;
        }
    }
    else
    {
        if(x<n&&a[x]<=a[x+1])
        {
            auto Rt=st.lower_bound(x);
//            Rt++;
            R=*Rt;
            st.erase(Rt);
            Upd(R,-pw[R-(x+1)+1]);
        }
    }
    
    Upd(R,pw[R-L+1]);
    st.insert(R);
    
}

ll query(int l,int r)
{
//    for(int i=1;i<=n;i++)
//    {
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;
    int L,R;
    ll ans=0ll;
    auto Lt=st.lower_bound(l);
    L=*Lt;
    if(L<r)
    {
        ans+=pw[L-l+1];
    }
    else
    {
        return pw[r-l+1];
    }
    
    auto Rt=st.lower_bound(r);
    Rt--;
    R=*Rt;
//    cout<<L<<' '<<R<<endl;
    ans+=qry(R)-qry(L);
    ans+=pw[r-R];
//    cout<<qry(R)-qry(L)<<endl;
    return ans;
}

int main()
{
    sync;
    for(int i=1;i<maxn;i++)
    {
        pw[i]=1ll*pw[i-1]+1ll*i;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int x;
    st.insert(0);
    int lst=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            st.insert(i);
            Upd(i,pw[i-lst]);
            lst=i;
        }
    }
    st.insert(n);
    Upd(n,pw[n-lst]);

    int op,y;
    while(q--)
    {
        cin>>op>>x>>y;
        if(op==1)
            upd(x,y);
        else
            cout<<query(x,y)<<endl;
    }
    
    
    return 0;
}