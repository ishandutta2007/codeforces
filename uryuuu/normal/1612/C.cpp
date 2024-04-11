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
const int maxn=4005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

ll k,x;

ll ck(ll mid)
{
    ll len=min(k,mid-1ll);
    ll sum=len*(len+1ll)/2ll;
    ll L;
    if(mid-1>k)
    {
        len=((mid-1ll)-k);
        L=k-1ll-len+1ll;
        sum+=(k-1ll+L)*len/2ll;
    }
//    cout<<sum<<endl;
    if(sum<x)
        return 1;
    return 0;
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>k>>x;
//        ck(1359011987);
//        ck(1608737403);
        ll l=1ll,r=2ll*k-1ll,mid,ans=0;
        while(l<r)
        {
            mid=(l+r)/2;
            if(ck(mid))
            {
                ans=max(ans,mid);
                l=mid+1;
            }
            else
                r=mid;
        }
        if(ck(l))
            ans=max(ans,l);
        cout<<ans<<endl;
    }
    return 0;
}