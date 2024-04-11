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
    ll k; cin >> k;

    vector<ll> fibo(n + 1, 1);

    for (int x = 2; x <= n; ++x)
        fibo[x] = fibo[x - 1] + fibo[x - 2];

    vector<int> p(n);
    iota(all(p), 0);

    for (int i = 0; i < n; ++i)
    {
        if (fibo[n - i - 1] < k)
        {
            swap(p[i], p[i + 1]);
            k -= fibo[n - i - 1];
            i += 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << p[i] + 1 << "\n "[i + 1 < n];
    }

    exit(0);
}