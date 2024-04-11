#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n, m;
    cin >> n >> m;

    int mex = n;

    for (int j = 0; j < m; ++j)
    {
        int l, r;
        cin >> l >> r;
        mex = min(mex, r - l + 1);
    }

    cout << mex << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i % mex << "\n "[i + 1 < n];
    }



    exit(0);
}