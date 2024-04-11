// 1114E
// Arithmetic Progression

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define maxn 100010
#define pb push_back

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, bsl, bsu, bsm, g, s;
bool visited[1000010];
vector<ll> fn;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> n;
    bsl = 0; bsu = (ll)1e9;
    while (bsl != bsu) {
        bsm = (bsl + bsu) / 2;
        cout << "> " << bsm << endl << flush;
        cin >> m;
        if (m == 0) bsu = bsm;
        else bsl = bsm + 1;
    }

    for (i = 0; i < min(n, (ll)30); i++) {
        m = uniform_int_distribution<ll>(1, n)(rng);
        while (visited[m]) m = uniform_int_distribution<ll>(1, n)(rng);
        visited[m] = true;
        cout << "? " << m << endl << flush;
        cin >> m; fn.pb(m);
    }

    g = abs(fn[1] - fn[0]);
    s = fn.size();
    for (i = 1; i < s - 1; i++) {
        g = __gcd(g, abs(fn[i + 1] - fn[i]));
    }

    cout << "! " << bsl - g * (n - 1) << ' ' << g << endl << flush;

    return 0;
}