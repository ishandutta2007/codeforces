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
    string s; cin >> s;

    int k; cin >> k;

    int w[26];
    for (int i = 0; i < 26; ++i) cin >> w[i];

    int ans = 0;
    for (int i = 0; i < sz(s); ++i)
        ans += w[s[i] - 'a'] * (i + 1);

    int MAX = *max_element(w, w + 26);

    for (int i = sz(s); i < sz(s) + k; ++i)
        ans += MAX * (i + 1);

    cout << ans << endl;

    exit(0);
}