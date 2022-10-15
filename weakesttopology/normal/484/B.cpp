#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n; cin >> n;

    vector<int> a(n);

    for (auto& x : a) cin >> x;

    sort(all(a)), a.erase(unique(all(a)), end(a));

    n = size(a);

    int ans = 0;

    for (int i = n - 2; i >= 0; --i)
    {
        int x = a[i];

        auto iter = i + begin(a) + 1;

        for (int k = 2; iter != end(a); ++k)
        {
            iter = lower_bound(iter, end(a), k * x);

            ans = max(ans, *prev(iter) % x);
        }
    }

    cout << ans << endl;

    exit(0);
}