#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int query(int t, int i, int j, int x) {
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void answer(vector<int>& p) {
    p.erase(begin(p));
    cout << "!";
    for (auto x : p) cout << " " << x;
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1, -1);

    int y = n;
    for (int x = 1; x + 1 <= n; x += 2) {
        int A = query(1, x, x + 1, n - 1);
        if (A == n) {
            if (query(2, x, x + 1, n - 1) == n) {
                y = x;
            }
            else y = x + 1;
            break;
        }
        if (A == n - 1) {
            if (query(2, x, x + 1, n - 1) == n) {
                y = x;
                break;
            }
        }
    }
    p[y] = n;

    for (int x = 1; x <= n; ++x) if (x != y) {
        p[x] = query(2, x, y, 1);
    }
    answer(p);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}