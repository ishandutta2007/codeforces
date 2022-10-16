#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n), t(n);
    for (auto& x : v) cin >> x;
    for (auto& x : t) cin >> x;

    priority_queue<ll> pq;
    ll prefsum = 0, cnt = 0;

    for (int i = 0; i < n; ++i) {
        pq.push(-(prefsum + v[i]));
        prefsum += t[i], cnt += 1;

        ll melted = t[i] * cnt;
        while (not empty(pq) && -pq.top() <= prefsum) {
            melted -= prefsum + pq.top(), cnt -= 1;
            pq.pop();
        }

        cout << melted << "\n "[i + 1 < n];
    }

    exit(0);
}