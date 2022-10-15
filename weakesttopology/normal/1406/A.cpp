#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int solve()
{
    int n; cin >> n;
    map<int, int> F;
    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;
        F[a]++;
    }

    int A = INF, B = INF;

    for (int i = 0; i < 200; ++i)
    {
        if (F[i] == 0) A = min(A, i);
        if (F[i] <= 1) B = min(B, i);
    }
    return A + B;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}