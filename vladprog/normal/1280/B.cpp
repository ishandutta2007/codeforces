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

const int N=70;

string s[N];
int cnti[N],cntj[N];

int solve()
{
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++)
        cin>>s[i];
    for(int i=0;i<r;i++)
        cnti[i]=0;
    for(int j=0;j<c;j++)
        cntj[j]=0;
    int cnta=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(s[i][j]=='A')
                cnta++,
                cnti[i]++,
                cntj[j]++;
    if(cnta==0)
        return -1;
    if(cnta==c*r)
        return 0;
    if(cnti[0]==c||cnti[r-1]==c||cntj[0]==r||cntj[c-1]==r)
        return 1;
    for(int i=0;i<r;i++)
        if(cnti[i]==c)
            return 2;
    for(int j=0;j<c;j++)
        if(cntj[j]==r)
            return 2;
    if(s[0][0]=='A'||s[0][c-1]=='A'||s[r-1][0]=='A'||s[r-1][c-1]=='A')
        return 2;
    if(cnti[0]||cnti[r-1]||cntj[0]||cntj[c-1])
        return 3;
    return 4;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int ans=solve();
        if(ans==-1)
            cout<<"MORTAL\n";
        else
            cout<<ans<<"\n";
    }
}