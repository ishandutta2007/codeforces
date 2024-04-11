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

const int N=2e5+100;

pair<char,int> di[N];

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
        string d;
        cin>>n>>d;
        for(int i=0;i<n;i++)
            di[i]={d[i],i};
        sort(di,di+n);
        string ans(n,'2');
        int bad=-1;
        for(int i=0;i<n;i++)
            if(i==0||di[i].second>di[i-1].second)
                ans[di[i].second]='1';
            else
            {
                bad=i;
                break;
            }
        for(int i=di[bad-1].second;i<n;i++)
            if(d[i]==di[bad].first)
                ans[i]='1';
        string srt;
        for(int i=0;i<n;i++)
            if(ans[i]=='1')
                srt+=d[i];
        for(int i=0;i<n;i++)
            if(ans[i]=='2')
                srt+=d[i];
        bool ok=true;
        for(int i=1;i<n;i++)
            if(srt[i]<srt[i-1])
                ok=false;
        if(ok)
            cout<<ans<<"\n";
        else
            cout<<"-\n";
    }
}