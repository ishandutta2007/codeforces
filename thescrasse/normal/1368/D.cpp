#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], bt, l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i]; b[i] = 0;
    }

    for (bt = 0; bt <= 22; bt++) {
        l = 0;
        for (i = 0; i < n; i++) {
            if (((a[i] >> bt) & 1) == 1) {
                b[l] += (1 << bt); l++;
            }
        }
    }

    res = 0;
    for (i = 0; i < n; i++) {
        res += (b[i] * b[i]);
    }

    cout << res;

    return 0;
}