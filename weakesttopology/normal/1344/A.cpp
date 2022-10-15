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

string solve()
{
    int n; cin >> n;

    vector a(n, 0);

    for (auto& x : a)
    {
        cin >> x;
        x = (x % n + n) % n;
    }

    int N = 2 * n;

    vector rooms(N, 0);

    for (int x = 0; x < N; ++x)
        if (x + a[x % n] < N) rooms[x + a[x % n]]++;

    int minimum = *min_element(n + all(rooms));
    int maximum = *max_element(n + all(rooms));

    return minimum == maximum ? "YES" : "NO";
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}