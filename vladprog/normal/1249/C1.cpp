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
        int n;
        cin>>n;
        vector<int> v;
        while(n)
            v.push_back(n%3),
            n/=3;
        v.push_back(0);
        int two=-1;
        for(int i=0;i<v.size();i++)
            if(v[i]==2)
            two=i;
        if(two!=-1)
        {
            int zero;
            for(int i=v.size()-1;i>two;i--)
                if(v[i]==0)
                    zero=i;
            for(int i=0;i<zero;i++)
                v[i]=0;
            v[zero]=1;
        }
        int m=0;
        for(int i=v.size()-1;i>=0;i--)
            m=m*3+v[i];
        cout<<m<<"\n";
    }
}