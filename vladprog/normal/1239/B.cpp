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

const int N=3e5+100;

int d[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin>>n>>s;
    s="_"+s;
    int m=0;
    for(int i=1;i<=n;i++)
        m=min(m,d[i]=d[i-1]+(s[i]=='('?1:-1));
    if(d[n])
        cout<<"0\n1 1",exit(0);
    for(int i=1;i<=n;i++)
        d[i]-=m;
    int cnt0=count(d+1,d+n+1,0);
    int cur,from;

    cur=0,from=0;
    int best1=0,x1=1,y1=1;
    for(int i=1;i<=n;i++)
        if(d[i]<=1)
            cur=0,from=0;
        else
        {
            if(d[i]==2)
                cur++;
            if(!from)
                from=i;
            if(cur>best1)
                best1=cur,x1=from,y1=i%n+1;
        }
    for(int i=1;i<=n;i++)
        if(d[i]<=1)
            cur=0,from=0;
        else
        {
            if(d[i]==2)
                cur++;
            if(!from)
                from=i;
            if(cur>best1)
                best1=cur,x1=from,y1=i%n+1;
        }
    best1+=cnt0;

    cur=0,from=0;
    int best2=0,x2=1,y2=1;
    for(int i=1;i<=n;i++)
        if(d[i]<=0)
            cur=0,from=0;
        else
        {
            if(d[i]==1)
                cur++;
            if(!from)
                from=i;
            if(cur>best2)
                best2=cur,x2=from,y2=i%n+1;
        }
    for(int i=1;i<=n;i++)
        if(d[i]<=0)
            cur=0,from=0;
        else
        {
            if(d[i]==1)
                cur++;
            if(!from)
                from=i;
            if(cur>best2)
                best2=cur,x2=from,y2=i%n+1;
        }

    if(best1>best2)
        cout<<best1<<"\n"<<x1<<" "<<y1;
    else
        cout<<best2<<"\n"<<x2<<" "<<y2;
}