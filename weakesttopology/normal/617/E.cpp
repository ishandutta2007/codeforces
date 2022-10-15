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
    int n, q, k; cin >> n >> q >> k;

    vector a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) a[i] ^= a[i - 1];

    vector<int> l(q, 0), r(q, 0);
    for (int z = 0; z < q; ++z)
    {
        cin >> l[z] >> r[z];
        --l[z];
    }

    int B = 1;
    while (B * B <= n) ++B;

    vector<int> I(q, 0); iota(all(I), 0);
    sort(all(I), [&](int i, int j)
        {
            if (l[i] / B != l[j] / B) return l[i] / B < l[j] / B;
            if ((l[i] / B) & 1) return r[j] < r[i];
            else return r[i] < r[j];
        }
    );

    const int N = 1 << 20;

    vector mark(N, 0); mark[0] = 1;

    int lcur = 0, rcur = 0; ll ct = 0;

    auto remove = [&](int x) { mark[x]--; ct -= mark[x ^ k]; };
    auto insert = [&](int x) { ct += mark[x ^ k]; mark[x]++; };

    auto update = [&](int l, int r)
    {
        while (l < lcur) insert(a[--lcur]);
        while (rcur < r) insert(a[++rcur]);
        while (lcur < l) remove(a[lcur++]);
        while (r < rcur) remove(a[rcur--]);
    };

    vector ans(q, 0LL);
    for (auto z : I)
    {
        update(l[z], r[z]);
        ans[z] = ct;
    }

    for (int z = 0; z < q; ++z)
        cout << ans[z] << endl;

    exit(0);
}