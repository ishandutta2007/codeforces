#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
typedef long long ll;

const int N = 300100;
map<ll, ll> a;
ll k;
ll q[N];
ll b[N], c[N];
ll z;

ll ans = 0;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        if (k != 1 && q[i] % k == 0 && q[i] != 0)
            b[i] = a[q[i] / k];
        if (a.count(q[i]) == 0)
            a[q[i]] = 0;
        a[q[i]]++;
        if (q[i] == 0) z++;
    }
    if (k == 1)
    {
        for (auto p : a)
        {
            ll s = p.second;
            if (s < 3) continue;
            ans += s * (s - 1) * (s - 2) / 6;
        }
        cout << ans << endl;
        return 0;
    }

    a.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        if (q[i] != 0)
            c[i] = a[q[i] * k];
        if (a.count(q[i]) == 0)
            a[q[i]] = 0;
        a[q[i]]++;
    }

    ans = z * (z - 1) * (z - 2) / 6LL;
    for (int i = 0; i < n; i++)
        ans += b[i] * c[i];
    cout << ans << endl;

    return 0;
}