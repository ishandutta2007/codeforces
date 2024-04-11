#include <bits/stdc++.h>
using namespace std;

int fact[200005];
int finv[200005];
constexpr int MOD = 1000000007;

int C(int a, int b)
{
    return fact[a] * 1ll * finv[b] % MOD * finv[a - b] % MOD;
}

vector<int> dat;

vector<int> nxt(vector<int> vt, bool &f)
{
    vector<int> ret;

    for (int i = 1; i < vt.size(); i++)
    {
        ret.push_back(((vt[i - 1] + vt[i] * (f ? -1 : 1)) % MOD + MOD) % MOD);
        f ^= true;
    }

    return ret;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) fact[i] = fact[i - 1] * 1ll * i % MOD;
    finv[200000] = 750007460;
    for (int i = 199999; i >= 0; i--) finv[i] = finv[i + 1] * 1ll * (i + 1) % MOD;

    int n;
    scanf("%d",&n);
    dat.resize(n);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);

    bool f = false;
    while (dat.size() % 4 != 1) dat = nxt(dat, f);

    int z = (dat.size() - 1) / 2;
    int ret = 0;
    for (int i = 0; i < dat.size(); i += 2)
    {
        ret = (ret + C(z, i / 2) * 1ll * dat[i]) % MOD;
    }

    printf("%d\n", ret);
}