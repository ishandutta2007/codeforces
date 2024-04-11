#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y, z;
    cin >> x >> y >> z;
    int w = x - y;
    char ans = '?';

    if (w - z > 0)
        ans = '+';
    else if (w + z < 0)
        ans = '-';
    else if (w == 0 && z == 0)
        ans = '0';
    cout << ans << endl;

    return 0;
}