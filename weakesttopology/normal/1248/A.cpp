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
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        ll x[2] = { 0, 0 };
        for (int i = 0; i < n; ++i)
        {
            int p; cin >> p;
            x[p % 2]++;
        }

        int m; cin >> m;
        ll y[2] = { 0, 0 };
        for (int j = 0; j < m; ++j)
        {
            int q; cin >> q;
            y[q % 2]++;
        }
        ll c = x[0] * y[0] + x[1] * y[1];

        cout << c << endl;
    }
    exit(0);
}