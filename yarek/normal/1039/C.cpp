#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500001, mod = 1000000007;
ll c[N];

int r[N];
int comp;

int Find(int k)
{
    if(r[k] != k) r[k] = Find(r[k]);
    return r[k];
}

void Union(int a, int b)
{
    a = Find(a); b = Find(b);
    if(a != b)
    {
        comp--;
        r[a] = b;
    }
}

unordered_map<ll, vector<pair<int, int>>> e;
ll p2[N];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    p2[0] = 1;
    for(int i = 1; i <= n; i++)
        p2[i] = p2[i-1] * 2 % mod;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", c + i);
        r[i] = i;
    }
    while(m--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        e[c[u] ^ c[v]].emplace_back(u, v);
    }
    ll ans = ((1LL << k) - e.size()) % mod * p2[n] % mod;
    for(auto &p: e)
    {
        auto &vec = p.second;
        comp = n;
        for(auto x: vec)
            Union(x.first, x.second);
        ans = (ans + p2[comp]) % mod;
        for(auto x: vec)
        {
            r[x.first] = x.first;
            r[x.second] = x.second;
        }
    }
    printf("%lld\n", ans);
}