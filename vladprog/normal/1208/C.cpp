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

int a[N][N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int t=0;
    for(int i=0;i<n/4;i++)
        for(int j=0;j<n/4;j++)
            for(int x=0;x<4;x++)
                for(int y=0;y<4;y++)
                    a[i*4+x][j*4+y]=t++;
    for(int i=0;i<n;i++,cout<<"\n")
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
//    for(int i=0;i<n;i++,cout<<"\n")
//    {
//        int x=0;
//        for(int j=0;j<n;j++)
//            x^=a[i][j];
//        cout<<x;
//    }
//    for(int i=0;i<n;i++,cout<<"\n")
//    {
//        int x=0;
//        for(int j=0;j<n;j++)
//            x^=a[j][i];
//        cout<<x;
//    }

}