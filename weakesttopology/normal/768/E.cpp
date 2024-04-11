#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;
using ull = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    constexpr int smax = 60;
    bitset<smax> fullmask; fullmask.set();

    map<pair<int, ull>, int> memo;

    function<int(int, bitset<smax>)> solve = [&](int x, bitset<smax> taken)
    {
        pair<int, ull> pxtaken(x, taken.to_ulong());
        if (memo.count(pxtaken)) return memo[pxtaken];

        vector<int> nxt;
        for (int i = 1; i <= x; ++i) if (not taken[i - 1])
        {
            taken[i - 1] = 1;
            bitset<smax> nxt_taken = taken & (fullmask >> (smax - (x - i)));
            nxt.push_back(solve(x - i, nxt_taken));
            taken[i - 1] = 0;
        }

        sort(all(nxt)), nxt.erase(unique(all(nxt)), end(nxt));

        int mex = 0;
        while (mex < size(nxt) && nxt[mex] == mex) ++mex;

        return memo[pxtaken] = mex;
    };

    vector<int> grundy(smax + 1, 0);

    for (int x = 1; x <= smax; ++x) grundy[x] = solve(x, 0);

    int n; cin >> n;

    int xor_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        int s; cin >> s;
        xor_sum ^= grundy[s];
    }

    string ans = xor_sum ? "NO" : "YES";

    cout << ans << endl;

    exit(0);
}