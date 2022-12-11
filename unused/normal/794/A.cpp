#include <bits/stdc++.h>
using namespace std;

int x[100005];

int main()
{
    cin.sync_with_stdio(false);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        if (b < x[i] && x[i] < c) ++ans;
    }
    cout << ans << endl;
}