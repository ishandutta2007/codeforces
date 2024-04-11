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

const int MOD=1e9+7;


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int x;
        string s;
        cin>>x>>s;
        int n=s.size(),cur=0;
        s="_"+s;
        for(int l=1;l<=x;l++)
        {
            cur=(s[l]-'0');
            n=(l+(n-l)*cur)%MOD;
            for(int i=l+1,sz=s.size()-1;s.size()-1<n&&s.size()-1<x;i++)
            {
                if(i==sz+1)
                    i=l+1;
                s+=s[i];
            }
//            cout<<s<<"\n";
        }
        cout<<(n+MOD)%MOD<<"\n";
    }
}