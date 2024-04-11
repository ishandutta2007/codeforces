#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve()
{
    int n, x; cin >> n >> x;
    map<int, int> H;

    int SUM = 0;
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        H[a]++;
        SUM += a;
    }
    if (H[x] == n) return 0;
    if (SUM == n * x || H[x]) return 1;
    return 2;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}