// 1208F
// Bits and Pieces

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 4200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll cn[maxn], mx2[maxn], bsl;

void ins(ll mask, ll l, ll p) {
    ll i;
    if (cn[mask] >= 2) return;
    cn[mask]++;
    if (cn[mask] == 2) mx2[mask] = p;
    for (i = l + 1; i <= 21; i++) {
        if ((mask >> i) & 1) {
            ins(mask ^ (1 << i), i, p);
        }
    }
}

bool good(ll x) {
    ll i, k;
    for (i = 1; i <= n; i++) {
        k = x & (((1 << 22) - 1) ^ a[i]);
        if (mx2[k] > i) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = n; i >= 1; i--) {
        ins(a[i], -1, i);
    }

    bsl = 0;
    for (i = 21; i >= 0; i--) {
        if (good(bsl + (1 << i))) bsl += (1 << i);
    }

    cout << bsl << nl;

    return 0;
}