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

int a[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    int q;
    cin>>q;
    map<pair<int,int>,int> m;
    while(q--)
    {
        int s,t,u;
        cin>>s>>t>>u;
        int&x=m[{s,t}];

        if(x&&a[x]>=0)
            sum++;
        a[x]++;

        x=u;

        if(x&&a[x]>0)
            sum--;
        a[x]--;
        cout<<sum<<"\n";
    }
}