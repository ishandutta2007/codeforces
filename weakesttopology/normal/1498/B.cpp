#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve()
{
    int n, W;
    cin >> n >> W;

    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(rall(a));

    vector<int> B(n, W);

    for (auto x : a)
    {
        auto iter = lower_bound(all(B), x);
        int i = (int)distance(begin(B), iter);
        B[i] -= x;
    }

    return n - (int)count(all(B), W);
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}