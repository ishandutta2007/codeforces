#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for(auto&a:(x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

int main() {
    cin.sync_with_stdio(0);

    int m; cin >> m;
    int q = INT_MAX;

    rep(i, 0, m) {
        int k; cin >> k;
        q = min(q, k);
    }

    int n; cin >> n;
    Vi need(n);
    each(e, need) cin >> e;
    sort(all(need));
    reverse(all(need));

    ll ans = 0;
    rep(i, 0, n) {
        if (i % (q+2) < q) ans += need[i];
    }

    cout << ans << '\n';
    return 0;
}