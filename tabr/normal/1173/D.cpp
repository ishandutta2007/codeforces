#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

ll mod = 998244353LL;
ll fac[200010], q[200010];
int n;
vector<set<int>> p(200010);

void cinit()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i < 200010; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        q[i] = 0;
    }
}

ll dfs(int k)
{
    q[k] = 1;
    ll r = 1;
    int l = p[k].size();
    for (auto x : p[k])
    {
        if (q[x] == 0)
        {
            r *= dfs(x);
            r %= mod;
        }
    }
    q[k] = r * fac[l] % mod;
    return q[k];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cinit();

    cin >> n;
    rep(i, n - 1)
    {
        int s, t;
        cin >> s >> t;
        p[s].insert(t);
        p[t].insert(s);
    }

    cout << (dfs(1) * n) % mod << endl;

    return 0;
}