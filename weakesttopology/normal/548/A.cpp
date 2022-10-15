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

    int n = size(s);

    int k; cin >> k;

    string ans = "NO";

    if (n % k == 0)
    {
        int x = n / k;

        string t = s;

        for (int i = 0; i < n; i += x)
        {
            reverse(begin(t) + i, begin(t) + i + x);
        }

        if (t == s) ans = "YES";
    }

    cout << ans << endl;

    exit(0);
}