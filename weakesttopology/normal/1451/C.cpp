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

string solve()
{
    int n, k; cin >> n >> k;

    int a[26] = { 0 }, b[26] = { 0 };

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        a[c - 'a'] += 1;
    }

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        b[c - 'a'] += 1;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (a[i] < b[i] || (a[i] - b[i]) % k) return "NO";

        if (i + 1 < 26) a[i + 1] += a[i] - b[i];

        else if (a[i] != b[i]) return "NO";
    }

    return "YES";
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() <<endl;
    exit(0);
}