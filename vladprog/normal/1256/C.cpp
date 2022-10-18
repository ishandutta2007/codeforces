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

const int N=1010;

int c[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,d;
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++)
        cin>>c[i];
    int s=accumulate(c+1,c+m+1,0ll);
    int x=(n-s)/(m+1);
    int y=(n-s)%(m+1);
    if(x>=d||x==d-1&&y)
        cout<<"NO",exit(0);
    cout<<"YES\n";
    for(int _=0;_<x;_++)
        cout<<0<<" ";
    for(int i=1,p=x+1;i<=m;i++)
    {
        while(c[i]--)
            cout<<i<<" ",
            p++;
        for(int _=0;_<x;_++)
            cout<<0<<" ",
            p++;
        if(y)
            cout<<0<<" ",
            p++,
            y--;
    }
}