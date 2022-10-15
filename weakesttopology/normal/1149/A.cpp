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
    int n; cin >> n;

    vector<int> a(n);

    int parity = 0;

    for (auto& x : a)
    {
        cin >> x;
        parity ^= x & 1;
    }

    sort(all(a));

    if (parity == 0) swap(a[0], a[n - 1]);
    else if (n >= 2 && a[1] == 2) swap(a[0], a[1]);

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << "\n "[i + 1 < n];
    }

    exit(0);
}