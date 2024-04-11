#include <iostream>
#include <set>

using namespace std;
using ll = long long;

ll calc(ll n, ll k) {
    ll m = n / k;
    return m + m * (m - 1) / 2 * k;
}

int main() {
    ll N;
    cin >> N;

    set<ll> ans;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i > 0) continue;
        ans.insert(calc(N, i));
        ans.insert(calc(N, N / i));
    }

    for (ll f : ans) cout << f << " ";

    cout << endl;
    return 0;
}