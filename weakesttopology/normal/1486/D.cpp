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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto check = [&](int y)
    {
        auto b = a;
        for (auto& x : b) x = (x >= y ? +1 : -1);

        int min_prefix = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i) b[i] += b[i - 1];
            if (i >= k - 1)
            {
                if (b[i] - min_prefix > 0) return true;
                min_prefix = min(min_prefix, b[i - k + 1]);
            }
        }

        return false;
    };

    int res = 0;
    for (int z = n; z; z >>= 1) while (check(res + z)) res += z;

    cout << res << endl;

    exit(0);
}