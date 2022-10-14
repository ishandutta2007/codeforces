#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 2000
#define N 2000000
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,w,h,l,timer;
ll a[2000500], pa[2005000], pb[2005000];
vector<ll> ans;
map<ll,ll> used, divs, dp;
ll do_magic(ll x, ll y)
{
    ll ans = x;
    for (int i = y; (1<<i) <= x; i++)
    {
        if ((ans&(1<<i)) != 0)
        {
            if (i-y-1>=0)
            ans |= (1<<i-y-1);
            ans ^= (1<<i);
        }
    }
    return ans;
}
ll mag(ll x)
{
    vector<ll> f;

    f.push_back(-1);
    for (int i = 0; (1<<i) <= x; i++)
    {
        if ((x&(1<<i)) != 0)
            f.push_back(i);
    }
    ll mx = 0;
    for (int i = 0; i+1 < f.size(); i++)
        mx = max(mx, f[i+1] - f[i]);
    return mx;
}
string bin(ll x)
{
    string s;
    while (x)
    {
        s.push_back('0'+x%2);
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
void dfs(ll x)
{
    if (used[x])
        return;
    used[x] = 1;
    for (int i = 0; (1<<i) <= x; i++)
        dfs(do_magic(x,i));
}
ll solve(ll n)
{
    used.clear();
    dfs(n);
    dp.clear();
    for (auto itr = used.begin(); itr != used.end(); itr++)
    {
        ll val = (*itr).X;
        //cout << val << endl;
        if (val == 0)
            dp[val] = 0;
        else
        {
            ll tmp = 0, j;
            for (j = 0; (1<<j) <= val; j++)
                tmp |= (1<<dp[do_magic(val, j)]);
            for (j = 0; (1<<j) <= tmp; j++)
            {
                if ((tmp & (1<<j)) == 0)
                    break;
            }
            dp[val] = j;
        }
    }
    return dp[n];
}
int main() {
    //freopen("input.txt","w",stdout);
    ll result = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        for (j = 2; j <= 35000; j++)
        {
            if (x%j == 0)
            {
                ll cnt = 0;
                while (x%j == 0)
                    x /= j, cnt++;
                divs[j] |= (1<<(cnt-1));
            }
        }
        if (x != 1)
            divs[x] |= 1;
    }
    for (auto itr = divs.begin(); itr != divs.end(); itr++)
    {
        //cout << (*itr).Y << endl;
        result ^= solve((*itr).Y);
    }
    if (result == 0)
        cout << "Arpa" << endl;
    else
        cout << "Mojtaba" << endl;
    return 0;
}