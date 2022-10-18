#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n), c(n + 1);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
        c[b[i]] += i + 1;
    }

    rep(i, b[n - 1])
    {
        if (c[i + 1] != n - b[n - 1] + 1 + i)
            break;
        if (i + 1 == b[n - 1])
        {
            if (b[n - 1] == n)
            {
                cout << '0' << endl;
                return 0;
            }

            forx(j, b[n - 1] + 1, n + 1)
            {
                if (c[j] > j - b[n - 1] - 1)
                    break;
                if (j == n)
                {
                    cout << n - b[n - 1] << endl;
                    return 0;
                }
            }
        }
    }

    rep(i, n) ans = max(ans, c[i + 1] + n - i);
    cout << ans << endl;

    return 0;
}