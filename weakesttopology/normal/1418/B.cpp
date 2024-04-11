#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

void solve()
{
    int n; cin >> n;

    vector a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector l(n, 0);
    for (int i = 0; i < n; ++i) cin >> l[i];

    vector I(0, 0);
    for (int i = 0; i < n; ++i)
        if (not l[i]) I.push_back(i);

    auto cmp = [&](int i, int j) { return a[i] > a[j]; };
    sort(all(I), cmp);

    int j = 0;
    auto b = a;
    for (int i = 0; i < n; ++i)
        if (not l[i]) b[i] = a[I[j++]];

    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}