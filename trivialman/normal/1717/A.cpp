#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
int P = 998244353;
const int INF = 1e9 + 1;
const int N = 1005;
mt19937 rng(time(0));

int T, x;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> x;
        cout << x + x / 2 * 2 + x / 3 * 2 << "\n";
    }
    return 0;
}