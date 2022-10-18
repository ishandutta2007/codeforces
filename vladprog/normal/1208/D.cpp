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

int n;
int t[N];

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i <= n; i = (i | (i+1)))
		t[i] += delta;
}

int s[N],p[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        inc(i,i);
    for(int i=n;i>=1;i--)
    {
        int l=1,r=n;
//        cout<<i<<" : ";
        while(l<r)
        {
            int m=(l+r+1)/2;
            int cur=sum(m-1);
//            cout<<m<<"->"<<cur<<" ";
            if(cur<=s[i])
                l=m;
            else
                r=m-1;
        }
//        cout<<" : "<<l<<"\n";
        p[i]=l;
        inc(l,-l);
    }
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";
}