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
    string s; cin >> s;

    int q; cin >> q;

    for (int z = 0; z < q; ++z)
    {
        int l, r, k; cin >> l >> r >> k; --l, --r;

        k %= (r - l + 1);

        if (k != 0) rotate(begin(s) + l, begin(s) + r + 1 - k, begin(s) + r + 1);
    }

    cout << s << endl;

    exit(0);
}