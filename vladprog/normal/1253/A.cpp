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

const int N=1e5+100;

int d[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>d[i];
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            d[i]=x-d[i];
        }
        set<int> s(d+1,d+n+1);
        s.erase(0);
        if(s.size()>1)
            cout<<"NO\n";
        else if(s.empty())
            cout<<"YES\n";
        else if(*s.begin()<0)
            cout<<"NO\n";
        else
        {
            int t=0;
            for(int i=1;i<=n;i++)
                if(t%2==0&&d[i])
                    t++;
                else if(t%2==1&&!d[i])
                    t++;
            cout<<(t<=2?"YES\n":"NO\n");
        }
    }
}