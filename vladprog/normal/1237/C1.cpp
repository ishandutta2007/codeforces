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

const int N=5e4+100;

array<int,4> in[N];

int sq(int x)
{
    return x*x;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>in[i][0]>>in[i][1]>>in[i][2],in[i][3]=i;
    vector<array<int,3>> dist;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        dist.push_back(array<int,3>{sq(in[i][0]-in[j][0])+sq(in[i][1]-in[j][1])+sq(in[i][2]-in[j][2]),i,j});
    sort(dist.begin(),dist.end());
    set<int> s;
    for(int i=1;i<=n;i++)
        s.insert(i);
    for(auto d:dist)
        if(s.count(d[1])&&s.count(d[2]))
            cout<<d[1]<<" "<<d[2]<<"\n",
            s.erase(d[1]),s.erase(d[2]);
}