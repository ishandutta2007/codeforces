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

    constexpr int nmax = 500;
    int a[nmax][nmax]{}, b[nmax][nmax]{};

    int L = 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            L = lcm(L, a[i][j]);
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if ((i + j) % 2) b[i][j] = L;
            else
            {
                int x = a[i][j];
                b[i][j] = L + x * x * x * x;
            }
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cout << b[i][j] << "\n "[j + 1 < m];

    exit(0);
}