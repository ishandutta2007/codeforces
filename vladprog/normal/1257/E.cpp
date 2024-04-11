#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

const int N=2e5+100;

int s1[N],s2[N],s3[N];

#define sum(i)\
int sum##i(int l,int r)\
{\
    return s##i[r]-s##i[l-1];\
}
sum(1)
sum(2)
sum(3)

int best[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k1,k2,k3;
    cin>>k1>>k2>>k3;
    int n=k1+k2+k3;
    while(k1--)
    {
        int x;
        cin>>x;
        s1[x]=1;
    }
    while(k2--)
    {
        int x;
        cin>>x;
        s2[x]=1;
    }
    while(k3--)
    {
        int x;
        cin>>x;
        s3[x]=1;
    }
    for(int i=1;i<=n;i++)
        s1[i]+=s1[i-1],
        s2[i]+=s2[i-1],
        s3[i]+=s3[i-1];
    for(int i=1;i<=n+1;i++)
        best[i]=sum3(1,i-1)+sum2(i,n);
    for(int i=n;i>=1;i--)
        best[i]=min(best[i],best[i+1]);
    int ans=n;
    for(int i=0;i<=n;i++)
        ans=min(ans,sum2(1,i)+sum1(i+1,n)+best[i+1]);
    cout<<ans;
}