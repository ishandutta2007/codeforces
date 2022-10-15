#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<array<int, 2>> c(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        c[x][i >= l] += 1;
    }

    int odd[2]{};

    for (int x = 0; x < n; ++x) {
        int sum = c[x][0] + c[x][1];
        if (sum % 2) {
            if (c[x][0] > c[x][1]) {
                odd[0] += 1;
                c[x][0] -= 1;
            }
            else {
                odd[1] += 1;
                c[x][1] -= 1;
            }
        }
    }

    int cost = min(odd[0], odd[1]);
    odd[0] -= cost, odd[1] -= cost;

    for (int x = 0; x < n; ++x) {
        for (int t = 0; t < 2; ++t) {
            if (odd[t ^ 1] == 0 || c[x][t] < c[x][t ^ 1]) continue;
            int d = min(odd[t ^ 1], c[x][t] - c[x][t ^ 1]);
            d -= d % 2;
            odd[t ^ 1] -= d;
            c[x][t] -= d;
            cost += d;
        }
        cost += abs(c[x][0] - c[x][1]) / 2;
    }
    cost += odd[0] + odd[1];

    return cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) cout << solve() << endl;

    exit(0);
}