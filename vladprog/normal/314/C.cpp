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

const int MOD=1e9+7,A=1e6+100;

int dp[A],t[A];

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result = (result + t[r])%MOD;
	return result;
}

void inc (int i, int delta)
{
	for (; i < A; i = (i | (i+1)))
		t[i] = (t[i] + delta)%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    dp[0]=1;
    inc(0,1);
    while(n--)
    {
        int a;
        cin>>a;
        int nxt=sum(a)*a%MOD;
        inc(a,(nxt-dp[a]+MOD)%MOD);
        dp[a]=nxt;
    }
    cout<<(sum(A-1)+MOD-1)%MOD;
}