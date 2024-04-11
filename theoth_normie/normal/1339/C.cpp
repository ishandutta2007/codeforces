//------------NMFF0B0H--------//
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "evadingin.txt"
#define FILE_OUT "evadingout.txt"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
typedef long long ll;
//-----------RND------------//
ll n,num,m,i,j,ver[200001],prime[1000001],t,t1;
vector<ll> p,psum;
int main()
{
    fio;
    cin>>t;
    for (t1=1;t1<=t;t1++)
    {
        int mintime=0,maxx=-1e9-7;
        cin>>n;
        for (i=1;i<=n;i++) cin>>ver[i];
        for (i=1;i<=n;i++) 
        {
            maxx=max(maxx,ver[i]);
            mintime=max(mintime,maxx-ver[i]);
//            cout<<maxx-ver[i]<<' '<<mintime<<endl;
        }
        if (mintime==0) cout<<0<<endl;
        else
        cout<<floor(log2(mintime))+1<<endl;
    }
}