#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = (ll)1e9 + 7;

const int N = (int)5e6 + 100;
int p[N];

ll solve(ll x)
{
    ll res = 0;
    while(x > 1) {
        res += (x * (p[x] - 1)) / 2;
        x /= p[x];
    }
    return res;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    for (int i = 2; i < N; i++)
        p[i] = -1;
    for (int x = 2; x < N; x++) {
        if (p[x] != -1) continue;
        for (int y = x; y < N; y += x)
            if (p[y] == -1)
                p[y] = x;
    }

    ll ans = 0;
    ll t;
    int l, r;
    scanf("%lld%d%d", &t, &l, &r);
    for (int i = r; i >= l; i--) {
        ans = (ans * t + solve(i)) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}