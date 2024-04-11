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
        int n,k;
        string s;
        cin>>n>>k>>s;
        int cnt1=0;
        for(char c:s)
            if(c=='1')
                cnt1++;
            else if(k>=cnt1)
                cout<<"0",
                k-=cnt1;
            else
            {
                while(cnt1>k)
                    cout<<"1",
                    cnt1--;
                cout<<"0";
                while(cnt1)
                    cout<<"1",
                    cnt1--,
                    k--;
            }
        while(cnt1)
            cout<<"1",
            cnt1--;
        cout<<"\n";
    }
}