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

    int q;
    cin>>q;
    while(q--)
    {
        string s,t;
        cin>>s>>t;
        int cnts[26]={};
        for(char c:s)
            cnts[c-'a']++;
        int cntt[26]={};
        for(char c:t)
            cntt[c-'a']++;
        bool ok=false;
        for(int i=0;i<26;i++)
            if(cnts[i]&&cntt[i])
                ok=true;
        cout<<(ok?"YES\n":"NO\n");
    }
}