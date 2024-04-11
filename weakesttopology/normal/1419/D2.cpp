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

int main()
{ _
    int n; cin >> n;
    vector a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));

    vector b(n, -1);
    for (int i = 0; i < n; i += 2)
    {
        b[i] = a.back();
        a.pop_back();
    }

    reverse(all(a));
    int j = 0;

    for (int i = 1; i + 1 < n; i += 2)
    {
        while (j < sz(a) && a[j] >= min(b[i - 1], b[i + 1])) ++j;
        if (j < sz(a))
        {
            b[i] = a[j];
            a[j] = -1;
            ++j;
        }
    }

    reverse(all(a));
    j = 0;

    for (int i = 1; i + 1 < n; i += 2)
    {
        if (b[i] != -1) continue;
        while (j < sz(a) && a[j] == -1) ++j;
        if (j < sz(a))
        {
            b[i] = a[j];
            a[j] = -1;
            ++j;
        }
    }

    if (b.back() == -1)
    {
        j = 0;
        while (a[j] == -1) ++j;
        b.back() = a[j];
    }

    int ans = 0;
    for (int i = 1; i + 1 < n; i += 2)
        ans += b[i] < min(b[i - 1], b[i + 1]);

    cout << ans << endl;
    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << endl;

    exit(0);
}