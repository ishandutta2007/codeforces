#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/22, 23:59:12
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int mod = 998244353;
int n;
pii A[300000];
int fac[300001];

int get(map<pii, int> mp) {
    llong ret = 1;
    for (auto it : mp) ret = ret * fac[it.se] % mod;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    fac[0] = 1;
    map<pii, int> mp00, mp01, mp10, mp11;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++mp00[pii(0, 0)];
        ++mp01[pii(0, y)];
        ++mp10[pii(x, 0)];
        ++mp11[pii(x, y)];
        fac[i + 1] = fac[i] * (i + 1ll) % mod;
        A[i] = pii(x, y);
    }
    llong ret = get(mp00);
    ret += mod - get(mp01);
    ret += mod - get(mp10);
    sort(A, A + n);
    bool pos = 1;
    for (int i = 1; i < n; ++i) if (A[i - 1].se > A[i].se) pos = 0;
    if (pos) ret += get(mp11);
    printf("%lld\n", ret % mod);
    return 0;
}