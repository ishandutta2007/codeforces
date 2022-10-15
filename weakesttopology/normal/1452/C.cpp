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

int solve()
{
    string s; cin >> s;

    int open[2] = { 0, 0 };

    int ans = 0;

    for (auto c : s)
    {
        if (c == '(') open[0] += 1;
        if (c == ')' && open[0]) open[0] -= 1, ans += 1;

        if (c == '[') open[1] += 1;
        if (c == ']' && open[1]) open[1] -= 1, ans += 1;
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}