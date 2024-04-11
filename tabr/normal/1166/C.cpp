#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a.begin(), a.end());

    int j = 0;

    rep(i, n - 1)
    {
        ll x = a[i];
        j = max(j, i);

        if (j != n - 1)
            while (a[j + 1] <= 2 * x)
            {
                j++;
                if (j == n - 1)
                    break;
            }
        ans += (ll)(j - i);
    }
    cout << ans << endl;

    return 0;
}