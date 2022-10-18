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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    set<int> now,was;
    vector<int> ans;
    int last=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>0)
            if(now.count(x)||was.count(x))
                cout<<-1,exit(0);
            else
                now.insert(x),
                was.insert(x);
        else
            if(!now.count(-x))
                cout<<-1,exit(0);
            else
                now.erase(-x);
        if(now.empty())
            ans.push_back(i-last),
            last=i,
            was.clear();
    }
    if(!now.empty())
        cout<<-1,exit(0);
    cout<<ans.size()<<"\n";
    for(int x:ans)
        cout<<x<<" ";
}