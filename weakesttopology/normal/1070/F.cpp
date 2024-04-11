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

int main()
{ _
    int n; cin >> n;

    ll both = 0LL;

    int ctboth = 0;

    vector alice(0, 0LL), bob(0, 0LL), none(0, 0LL);

    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;

        ll x; cin >> x;

        if (s == "11")
            both += x, ctboth += 1;
        else if (s == "00")
            none.push_back(x);
        else if (s == "10")
            alice.push_back(x);
        else
            bob.push_back(x);
    }

    sort(rall(alice)), sort(rall(bob)), sort(rall(none));
    partial_sum(all(alice), begin(alice));
    partial_sum(all(bob), begin(bob));
    partial_sum(all(none), begin(none));

    ll base = both;

    if (size(alice) < size(bob)) swap(alice, bob);

    int cut = size(bob);

    if (not empty(bob)) base += bob[cut - 1];

    int B = ctboth + size(bob);

    debug(B);

    ll ans = base;

    debug(base);

    if (int x = ctboth - size(bob); not empty(none) && x > 0) ans += none[min(size(none), x) - 1];

    debug(ans);

    for (int x = 0; x < size(alice) && x < B; ++x)
    {
        ll cur = base + alice[x];

        int y = min({ size(none), B - (x + 1), ctboth - size(bob) + (x + 1) }) - 1;

        if (y >= 0) cur += none[y];

        ans = max(ans, cur);
    }

    cout << ans << endl;

    exit(0);
}