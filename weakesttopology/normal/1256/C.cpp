#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int n, m, d; cin >> n >> m >> d;
    vi c(n);
    int s = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> c[i];
        s += c[i];
    }

    if ((n - s + m) / (m + 1) <= d - 1)
    {
        cout << "YES\n";

        vi a(n, 0);
        int i = 0;
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < d - 1 && n - (i + k) < s; ++k)
                a[i + k] = 0;

            i = min(i + d - 1, n - s);

            s -= c[j];

            for (int k = 0; k < c[j]; ++k)
                a[i + k] = j + 1;

            i += c[j];
        }

        for (auto x : a)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "NO\n";

    exit(0);
}