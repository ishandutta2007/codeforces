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

int m[N][N],a[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>m[i][j];
    int g=0;
    for(int i=2;i<=n;i++)
        g=__gcd(g,m[i][1]);
    for(int i=2;i<=n;i++)
        a[i]=m[i][1]/g;
    int k=sqrt((ld)(m[2][3]/a[2]/a[3]));
    while(k*k<m[2][3]/a[2]/a[3])
        k++;
    while(k*k>m[2][3]/a[2]/a[3])
        k--;
    for(int i=2;i<=n;i++)
        a[i]*=k;
    a[1]=m[1][2]/a[2];
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}