#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, gsz, lsz, sp1, sp2, fr1, fr2, x, d;
vector<ll> ls, gt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> d >> m;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > m) gt.pb(a[i]);
        else ls.pb(a[i]);
    }

    sort(gt.begin(), gt.end()); reverse(gt.begin(), gt.end());
    sort(ls.begin(), ls.end()); reverse(ls.begin(), ls.end());
    gsz = gt.size(); lsz = ls.size();

    for (i = 1; i < gsz; i++) gt[i] += gt[i - 1];
    for (i = 1; i < lsz; i++) ls[i] += ls[i - 1];

    if (gsz == 0) {
        cout << ls[lsz - 1]; return 0;
    }

    res = 0;
    for (i = 1; i <= gsz; i++) {
        sp1 = (i - 1) * (d + 1) + 1;
        sp2 = min(sp1 + d, n);
        fr1 = sp1 - i; fr2 = sp2 - i;
        if (sp1 > n) continue;
        if (gsz - i > fr2) continue;
        k = max((ll)0, lsz - max((ll)0, (sp1 - gsz)));
        if (k == 0) x = gt[i - 1];
        else x = gt[i - 1] + ls[k - 1];
        res = max(res, x);
        // cout << i << ' ' << k << ' ' << x << nl;
    }

    cout << res;

    return 0;
}