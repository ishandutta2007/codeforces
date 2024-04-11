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
    int n, k, p; cin >> n >> k >> p;
    vi a(n);
    vii X(n);
    int o = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        o += a[i] % 2;
        X[i] = { a[i] % 2, a[i] };
    }
    sort(X.rbegin(), X.rend());

    if (o < k - p || o % 2 != (k - p) % 2 || (n - o + (o - (k-p)) / 2) < p)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;

        map<int, vi> H;
        int c = 0;

        int last = -1;
        for (int i = 0; i < k - p; ++i)
        {
            H[c++].pb(X[i].s);
            last = i;
        }
        for (int i = k - p; i < o && c < k; i += 2)
        {
            H[c].pb(X[i].s);
            H[c++].pb(X[i+1].s);
            last = i + 1;
        }
        for (int i = o; i < o + p - 1 - (o - (k-p)) / 2 && c < k; ++i)
        {
            H[c++].pb(X[i].s);
            last = i;
        }
        for (int i = max(o, o + p - 1 - (o - (k-p)) / 2); i < n && c < k; ++i)
        {
            H[c].pb(X[i].s);
            last = i;
        }
        for (int i = last + 1; i < n; ++i)
            H[c-1].pb(X[i].s);

        for (auto [k, v] : H)
        {
            cout << v.size();
            for (auto x : v)
                cout << " " << x;
            cout << endl;
        }
    }

    exit(0);
}