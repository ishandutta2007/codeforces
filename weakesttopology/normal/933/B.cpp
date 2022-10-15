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
    ll p, k;
    cin >> p >> k;

    vector<ll> a;

    for (ll x = p; x != 0;)
    {
        ll y = -(x / k);

        if (x < 0 && x % k) y += 1;

        a.push_back(k * y + x); 
        x = y;

    }

    int d = size(a);

    cout << d << endl;

    for (int i = 0; i < d; ++i) cout << a[i] << "\n "[i + 1 < d];

    exit(0);
}