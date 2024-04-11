#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;

#define pb push_back
#define x first
#define y second

#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    Vi seq(n);
    iota(all(seq), 0);
    sort(all(seq), [&](int l, int r) { return elems[l] < elems[r]; });
    rep(i, 0, n) elems[seq[i]] = i;

    int ans = 0;
    seq.assign(n, 0);

    each(e, elems) {
        seq[e] = 1;
        if (e > 0) seq[e] += seq[e-1];
        ans = max(ans, seq[e]);
    }

    cout << n-ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    run();
    return 0;
}