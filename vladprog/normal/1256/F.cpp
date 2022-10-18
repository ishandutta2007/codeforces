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

bool solve()
{
    int n;
    string s,t;
    cin>>n>>s>>t;
    string ss=s,tt=t;
    sort(ss.begin(),ss.end());
    sort(tt.begin(),tt.end());
    if(ss!=tt)
        return false;
    for(int i=0;i<n-1;i++)
        if(ss[i]==ss[i+1])
            return true;
    int x=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(s[i]>s[j])
                x++;
    int y=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(t[i]>t[j])
                y++;
    return x%2==y%2;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin>>q;
    while(q--)
        cout<<(solve()?"YES\n":"NO\n");
}