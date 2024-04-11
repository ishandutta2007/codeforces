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

    ll ans = 0;
    ll odd[2]{};

    for (int i = 0; i < n; ++i) {
        int x = i & 1;
        ll h;
        cin >> h;
        odd[x] += (h + 1) / 2;
        odd[x ^ 1] += h - (h + 1) / 2;
        ans += h;
    }

    ans -= max(odd[0], odd[1]);
    cout << ans << endl;

    exit(0);
}