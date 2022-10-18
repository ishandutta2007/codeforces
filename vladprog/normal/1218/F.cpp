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

const int N=1e5+100;

int x[N],c[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    int a;
    cin>>a;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    int ans=0;
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        s.insert(c[i]);
        while(k<x[i]&&!s.empty())
            ans+=*s.begin(),s.erase(s.begin()),k+=a;
        if(k<x[i])
            cout<<-1,exit(0);
    }
    cout<<ans;
}