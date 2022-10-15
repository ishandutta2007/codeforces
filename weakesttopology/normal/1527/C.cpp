#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll solve() {
    int n;
    cin >> n;

    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    ll ans = 0;
    for (auto& [x, I] : pos) {
        ll sum = 0;
        for (auto i : I) {
            ans += sum * (n - i);
            sum += i + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) cout << solve() << endl;

    exit(0);
}