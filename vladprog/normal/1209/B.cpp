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

const int N=110;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    int cur=count(s.begin(),s.end(),'1');
    int ans=cur;
    for(int i=1;i<=N*N;i++)
    {
        for(int j=0;j<n;j++)
            if(i>=b[j]&&b[j]%a[j]==i%a[j])
                s[j]=(s[j]=='0'?'1':'0');
//        cout<<i<<" -> "<<s<<"\n";
        cur=count(s.begin(),s.end(),'1');
        ans=max(ans,cur);
    }
    cout<<ans;
}