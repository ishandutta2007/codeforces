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

int l[N],r[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> seg;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        seg.push_back(mp(l[i],-i));
        seg.push_back(mp(r[i],i));
    }
    sort(seg.begin(),seg.end(),greater<pair<int,int>>());
    set<pair<int,int>,greater<pair<int,int>>> cur;
    vector<int> del;
    for(int i=0;i<=N;i++)
    {
        while(!seg.empty()&&seg.back().first==i&&seg.back().second<0)
            cur.insert(mp(r[-seg.back().second],-seg.back().second)),
            seg.pop_back();
        while(cur.size()>k)
        {
            del.push_back(cur.begin()->second);
            cur.erase(cur.begin());
        }
        while(!seg.empty()&&seg.back().first==i&&seg.back().second>0)
            cur.erase(mp(seg.back().first,seg.back().second)),
            seg.pop_back();
    }
    cout<<del.size()<<"\n";
    for(int x:del)
        cout<<x<<" ";
}