#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 505;
mt19937 rng(time(0));

int T, n, k, r, c;
char s[N][N];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> r >> c;
        memset(s,0,sizeof s);
        rep(i, 1, n) rep(j, 1, n) s[i][j] = (i + j - (r + c)) % k == 0 ? 'X' : '.';
        rep(i, 1, n) cout << (s[i] + 1) << "\n";
    }
    return 0;
}