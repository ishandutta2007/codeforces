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
    constexpr int emax = 30;

    map<ll, bitset<emax>> games;

    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        ll a; cin >> a;
        for (ll x = 2; x * x <= a; ++x) if (a % x == 0)
        {
            int ct = 0;
            while (a % x == 0) ct += 1, a /= x;
            games[x][ct - 1] = 1;
        }
        if (a > 1) games[a][0] = 1;
    }

    map<ull, int> memo;

    memo[0] = 0;

    function<int(bitset<emax>)> solve = [&](bitset<emax> mask)
    {
        ull maskulong = mask.to_ulong();
        if (memo.count(maskulong)) return memo[maskulong];

        vector<int> nxt;

        bitset<emax> prefix(0), suffix; suffix.set();
        for (int k = 0; k < emax; ++k) 
        {
            bitset<emax> prefix_cur = mask & prefix; 
            bitset<emax> suffix_cur = mask & suffix; 

            if (suffix_cur.none()) break;

            bitset<emax> nxt_mask = prefix_cur | (suffix_cur >> (k + 1));

            nxt.push_back(solve(nxt_mask));

            prefix[k] = 1, suffix <<= 1;
        }

        sort(all(nxt)), nxt.erase(unique(all(nxt)), end(nxt));
        int mex = 0;
        while (mex < size(nxt) && nxt[mex] == mex) ++mex;

        return memo[maskulong] = mex;
    };

    int xor_sum = 0;

    for (auto [p, mask] : games)
    {
        debug(p);
        xor_sum ^= solve(mask);
    }

    debug(xor_sum);

    string ans = xor_sum ? "Mojtaba" : "Arpa";

    cout << ans << endl;

    exit(0);
}