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

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector a(n, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.rbegin(), a.rend());

        vector b(0, 0);

        int g = a[0];
        for (int i = 0; i < n; ++i)
        {
            int f = -1;
            for (int j = 0; j < n; ++j)
                if (a[j] != -1)
                    f = max(f, gcd(a[j], g));

            for (int j = 0; j < n; ++j)
                if (a[j] != -1 && gcd(a[j], g) == f)
                    b.push_back(a[j]), a[j] = -1;

            g = f;
        }

        for (int i = 0; i < n; ++i) cout << b[i] << " ";
        cout << endl;
    }
    exit(0);
}