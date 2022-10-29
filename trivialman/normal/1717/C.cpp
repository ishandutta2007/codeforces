#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 9e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n;
int a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) cin >> b[i];
        bool flag = true;
        rep(i, 1, n)
        {
            if (b[i] - b[i % n + 1] >= 2 && b[i] != a[i])
                flag = false;
            if (b[i] < a[i])
                flag = false;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}