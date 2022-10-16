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

    vector p(2 * n, 0);

    iota(begin(p), begin(p) + n, 1);

    int l = 0, r = n - 1;

    for (int k = 2; k <= n; ++k, ++l, ++r)
    {
        int last = p[l];
        for (int i = l + k; i <= r; i += k) swap(last, p[i]);
        p[r + 1] = last;
    }

    for (int i = l; i <= r; ++i) cout << p[i] << "\n "[i < r];

    exit(0);
}