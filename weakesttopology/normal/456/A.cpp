#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n; cin >> n;

    vector L(n, pair(0, 0));

    for (auto& [a, b] : L) cin >> a >> b;

    sort(all(L));

    int prvmax = -1;

    string ans = "Poor Alex";

    for (auto [a, b] : L)
    {
        if (b < prvmax) ans = "Happy Alex";
        prvmax = max(b, prvmax);
    }

    cout << ans << endl;

    exit(0);
}