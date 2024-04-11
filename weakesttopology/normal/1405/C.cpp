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

string solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    for (int i = 0; i < k; ++i)
    {
        int ct[2] = { 0, 0 };
        for (int j = i; j < n; j += k)
        {
            if (s[j] == '0') ct[0]++;
            if (s[j] == '1') ct[1]++;
        }

        if (ct[0] && ct[1]) return "NO";

        if (ct[0] || ct[1])
        {
            for (int j = i; j < n; j += k)
                s[j] = ct[0] ? '0' : '1';
        }
    }

    int sum = 0, ct = 0;
    for (int i = 0; i < k; ++i)
    {
        if (s[i] == '0') sum--;
        if (s[i] == '1') sum++;
        if (s[i] == '?') ct++;
    }

    if (ct >= abs(sum)) return "YES";
    else return "NO";
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}