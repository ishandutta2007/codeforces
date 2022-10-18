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

const int M=110;

vector<int> a[M];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
            a[i]={0};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int x;
                cin>>x;
                a[j].push_back(x);
                a[j][0]=max(a[j][0],x);
            }
        while(m<4)
            a[++m].assign(n+1,0);
        sort(a+1,a+m+1,greater<vector<int>>());
//        for(int i=1;i<=4;i++)
//        {
//            cout<<i<<" -> ";
//            for(int j=1;j<=n;j++)
//                cout<<a[i][j]<<" ";
//            cout<<"\n";
//        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    ans=max(ans,(n>=1?max({a[1][1],a[2][i+1],a[3][j+1],a[4][k+1]}):0)+
                                (n>=2?max({a[1][2],a[2][(i+1)%n+1],a[3][(j+1)%n+1],a[4][(k+1)%n+1]}):0)+
                                (n>=3?max({a[1][3],a[2][(i+2)%n+1],a[3][(j+2)%n+1],a[4][(k+2)%n+1]}):0)+
                                (n>=4?max({a[1][4],a[2][(i+3)%n+1],a[3][(j+3)%n+1],a[4][(k+3)%n+1]}):0));
        cout<<ans<<"\n";
    }
}