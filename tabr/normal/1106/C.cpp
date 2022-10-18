#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define caseout(i, X) cout << "Case #" << i << ": " << X << endl;



int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;

    sort(a.begin(), a.end());

    rep(i, n) ans += a[i] * a[i];

    rep(i, n / 2) ans += 2*a[i] * a[n - i-1];

    cout << ans << endl;

    return 0;
}