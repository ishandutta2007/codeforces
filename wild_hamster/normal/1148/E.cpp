#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <math.h>
#include <assert.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;

typedef pair <int, int> pii;
typedef pair <ll, ll> pll;


void no() {
    cout << "NO";
    exit(0);
}

int main() {
    cout << setprecision(20);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n;
    cin >> n;
    vector<pll> s(n);
    vector<pll> t(n);

    for (int k = 0; k < n; ++k) {
        ll x;
        cin >> x;
        s[k] = mp(x, k);
    }
    for (int l = 0; l < n; ++l) {
        ll x;
        cin >> x;
        t[l] = mp(x, l);
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    ll cumm = 0;
    vl shifts(n);
    ll ups = 0;
    ll downs = 0;
    for (int i = 0; i < n; ++i) {
        ll shift = t[i].fi - s[i].fi;
        shifts[i] = shift;
        cumm += shift;
        if (cumm < 0) no();
        if (shift > 0) ++ups;
        if (shift < 0) ++downs;
    }
    if (cumm != 0) no();

    cout << "YES\n";
    vvl x;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (shifts[i] > 0) {
        while (j < n && shifts[j] >= 0) ++j;
        if (shifts[i] <= 0) continue;
        ll d = min(abs(shifts[i]), abs(shifts[j]));
        assert(d > 0);
        shifts[i] -= d;
        shifts[j] += d;
        x.pb({s[i].se + 1, s[j].se + 1, d});
        }
    }

    assert(x.size() < n * 5);
    cout << x.size() << endl;

    for (auto ans : x) {
        cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }

    return 0;

}