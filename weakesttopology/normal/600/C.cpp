#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    string s; cin >> s;

    int ct[26] = { 0 };

    for (auto c : s) ct[c - 'a'] += 1;

    vector<int> odd;

    for (int i = 0; i < 26; ++i) if (ct[i] % 2) odd.push_back(i);

    for (int l = 0, r = size(odd) - 1; l < r; ++l, --r)
        ct[odd[l]] += 1, ct[odd[r]] -= 1;

    string side, center;

    for (int i = 0; i < 26; ++i)
    {
        if (ct[i] % 2) center = string(1, char('a' + i));
        side += string(ct[i] / 2, char('a' + i));
    }

    string res = side + center;

    reverse(all(side));

    res += side;

    cout << res << endl;

    exit(0);
}