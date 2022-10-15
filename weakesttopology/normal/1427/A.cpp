#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
int size(const auto& X) { return (int)std::size(X); }

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void print(auto& a)
{
    cout << "YES" << endl;
    for (auto x : a) cout << x << " ";
    cout << endl;
}

void solve()
{
    int n; cin >> n;
    vector a(n, 0);
    for (auto& x : a) cin >> x;
    sort(all(a));

    bool good = true;
    for (int i = 0, sum = 0; i < n; ++i)
    {
        sum += a[i];
        if (sum == 0) good = false;
    }

    if (good)
    {
        print(a);
        return;
    }

    good = true;

    reverse(all(a));
    for (int i = 0, sum = 0; i < n; ++i)
    {
        sum += a[i];
        if (sum == 0) good = false;
    }

    if (good)
    {
        print(a);
        return;
    }

    cout << "NO" << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}