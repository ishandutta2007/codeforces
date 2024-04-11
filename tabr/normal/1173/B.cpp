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
    int m = (n + 2) / 2;
    cout << m << endl;

    for (int i = 1; i <= m; i++)
    {
        cout << 1 << ' ' << i << endl;
    }
    for (int i = m + 1; i <= n; i++)
    {
        cout << i - m + 1 << ' ' << m << endl;
    }

    return 0;
}