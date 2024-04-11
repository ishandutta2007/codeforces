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

const int N=2e5+100,L=20;

int a[N];
int st[L][N];
int best[N];

int get(int l,int r)
{
    int len=r-l+1;
    int j=31-__builtin_clz(len);
    return max(st[j][l],st[j][r-(1<<j)+1]);
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],st[0][i]=a[i];
        for(int j=1;j<L;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
        for(int i=0;i<=n;i++)
            best[i]=0;
        int m;
        cin>>m;
        while(m--)
        {
            int p,s;
            cin>>p>>s;
            best[s]=max(best[s],p);
        }
        for(int i=n-1;i>=1;i--)
            best[i]=max(best[i],best[i+1]);
        int pos=1,ans=0;
        while(pos<=n)
        {
            int l=0,r=n-pos+1;
            while(l<r)
            {
                int mid=(l+r+1)/2;
                if(best[mid]>=get(pos,pos+mid-1))
                    l=mid;
                else
                    r=mid-1;
            }
            if(!l)
            {
                ans=-1;
                break;
            }
            else
                pos+=l,
                ans++;
        }
        cout<<ans<<"\n";
    }
}