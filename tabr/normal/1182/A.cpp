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
    if (n % 2 == 1)
        cout << 0 << endl;
    else
    {
        int x = 1;
        rep(i, n / 2) x *= 2;
        cout << x << endl;
    }

    return 0;
}