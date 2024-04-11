#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cnt[1000005];

int main ()
{
    ios::sync_with_stdio(false);

    int n, m; ll dx, dy;
    cin >> n >> m >> dx >> dy;

    int mx = 0; pii ans(0, 0);
    for (int i = 0; i < m; i ++)
    {
        ll x, y; cin >> x >> y;
        ll cur = x * dy - y * dx;
        cur = (cur % n + n) % n, cnt[cur] ++;
        if (cnt[cur] > mx)
        {
            mx = cnt[cur];
            ans = pii(x, y);
        }
    }
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}