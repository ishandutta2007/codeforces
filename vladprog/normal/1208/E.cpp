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

const int N=1e6+100;

int a[N],ans[N];

void add(int l,int r,int val)
{
    ans[l]+=val;
    ans[r+1]-=val;
}

void add(int i,int val)
{
    add(i,i,val);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,w;
    cin>>n>>w;
    while(n--)
    {
        int l;
        cin>>l;
        for(int i=1;i<=l;i++)
            cin>>a[i];
        a[0]=a[l+1]=0;
        if(w<=2*l)
        {
            multiset<int,greater<int>> s;
            for(int i=0;i<=w+1;i++)
            {
                if(i<=l+1)
                    s.insert(a[i]);
                add(i,*s.begin());
                if(i+l-w>=0)
                    s.erase(s.find(a[i+l-w]));
            }
        }
        else
        {
            int m=0;
            for(int i=1;i<=l;i++)
            {
                m=max(m,a[i]);
                add(i,m);
            }
            m=0;
            for(int i=l;i>=1;i--)
            {
                m=max(m,a[i]);
                add(w-l+i,m);
            }
            add(l+1,w-l,m);
        }
    }
    for(int i=1;i<=w;i++)
        ans[i]+=ans[i-1];
    for(int i=1;i<=w;i++)
        cout<<ans[i]<<" ";
}