#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()
#define read(x) for (int xx = 0; xx < sz(x); ++xx) cin >> x[xx];

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int solve()
{
    string s; cin >> s;
    int n = sz(s);
    vi b;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0') continue;
        int c = 0;
        while (i < n && s[i] == '1')
            ++i, ++c;
        b.push_back(c);
    }
    sort(all(b)); reverse(all(b));
    int ans = 0;
    for (int i = 0; i < sz(b); i += 2)
        ans += b[i];
    return ans;
}

int main()
{ _
    int T; cin >> T;
    while (T--) cout << solve() << endl;
    exit(0);
}