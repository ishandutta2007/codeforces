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

char inv(char c)
{
    return c=='W'?'B':'W';
}

void solve(int n,string s,char c)
{
    vector<int> ans;
    for(int i=0;i<n-1;i++)
        if(s[i]!=c)
            s[i]=inv(s[i]),
            s[i+1]=inv(s[i+1]),
            ans.push_back(i+1);
    if(s.back()!=c)
        return;
    cout<<ans.size()<<"\n";
    for(int x:ans)
        cout<<x<<" ";
    exit(0);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin>>n>>s;
    solve(n,s,'B');
    solve(n,s,'W');
    cout<<-1;
}