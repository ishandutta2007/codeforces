#include <bits/stdc++.h>
using namespace std;

bool forbid[200005];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

vector<int> gcds;
vector<int> dat[200005];
bool v[200005];
int inmax[200005];
int dp[200005];

vector<int> toporder;
vector<int> ans;

void dfs1(int t)
{
    v[t] = true;
    for (int j = 0; j < gcds.size(); j++)
    {
        if (v[j]) continue;
        if (gcd(gcds[t], gcds[j]) == gcds[t])
        {
            dfs1(j);
        }
    }
    toporder.push_back(t);
}

void recur(int t)
{
    for (int x : dat[t]) ans.push_back(x);

    if (inmax[t] == 0) return;

    for (int i = 0; i < gcds.size(); i++)
    {
        if (i == t || gcd(gcds[i], gcds[t]) != gcds[i]) continue;
        if (dp[i] == inmax[t])
        {
            recur(i);
            return;
        }
    }
}
using ll = long long;
// find a pair (c, d) s.t. ac + bd = gcd(a, b)
pair<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return { 1, 0 };
    auto t = extended_gcd(b, a % b);
    return { t.second, t.first - t.second * (a / b) };
}
// find x in [0,m) s.t. ax === gcd(a, m) (mod m)
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first % m + m) % m;
}

int m;

int calc(int a, int b)
{
    int g = gcd(a, m);
    a /= g; b /= g;

    int ret = b * modinverse(a, m / g) % (m / g);
    return ret;
}

int main()
{
    int n;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        forbid[x] = true;
    }

    if (m == 1)
    {
        printf("1\n0\n");
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        if (forbid[i]) continue;
        gcds.push_back(gcd(i, m));
    }

    sort(gcds.begin(), gcds.end());
    gcds.erase(unique(gcds.begin(), gcds.end()), gcds.end());

    for (int i = 0; i < m; i++)
    {
        if (forbid[i]) continue;
        int idx = lower_bound(gcds.begin(), gcds.end(), gcd(i, m)) - gcds.begin();

        dat[idx].push_back(i);
    }

    for (int i = 0; i < gcds.size(); i++)
    {
        if (v[i]) continue;
        dfs1(i);
    }

    reverse(toporder.begin(), toporder.end());
    for (int t : toporder)
    {
        dp[t] = dat[t].size() + inmax[t];
        for (int i = 0; i < gcds.size(); i++)
        {
            if (i == t || gcd(gcds[t], gcds[i]) != gcds[t]) continue;
            inmax[i] = max(inmax[i], dp[t]);
        }
    }

    int maxidx = max_element(dp, dp + gcds.size()) - dp;

    recur(maxidx);

    printf("%zd\n", ans.size());
    reverse(ans.begin(), ans.end());
    int prv = 1;
    for (int t : ans)
    {
        printf("%d ", calc(prv, t));
        assert(calc(prv, t) * 1ll * prv % m == t);
        prv = t;
    }
    printf("\n");
}