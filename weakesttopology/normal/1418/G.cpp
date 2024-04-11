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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> unif(1e5, 1e12);

int main()
{ _
    int n; cin >> n;
    vector a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector H(n + 1, 0LL);
    for (int i = 0; i <= n; ++i)
        H[i] = unif(rng);

    ll HASH = 0;

    vector freq(n + 1, 0);
    vector prefix(n + 1, 0LL);
    for (int i = 0; i <= n; ++i)
    {
        int x = a[i];
        HASH -= H[x] * (freq[x] % 3);
        freq[x]++;
        HASH += H[x] * (freq[x] % 3);
        prefix[i] = HASH;
    }
    freq.assign(n + 1, 0);

    map<ll, int> ct;

    ll ans = 0;
    ct[prefix[0]] = 1;
    for (int r = 1, l = 0; r <= n; ++r)
    {
        while (freq[a[r]] > 3 || (freq[a[r]] == 3 && a[l] != a[r]))
        {
            --ct[prefix[l]];
            --freq[a[l++]];
        }
        ++freq[a[r]];
        ans += ct[prefix[r]]++;
    }

    cout << ans << endl;

    exit(0);
}