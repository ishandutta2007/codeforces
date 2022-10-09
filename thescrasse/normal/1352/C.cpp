#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b;
vector<ll> r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> k;
        m = k % (n - 1); k -= m;
        if (m == 0) m = -1;
        cout << k * n / (n - 1) + m << endl;
    }

    return 0;
}