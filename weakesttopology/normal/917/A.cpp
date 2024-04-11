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

constexpr int nmax = 5000;

bool prefix[nmax][nmax], suffix[nmax][nmax];

int main()
{ _
    string s;
    cin >> s;

    int n = size(s);

    for (int l = 0; l < n; ++l)
    {
        int balance = 0;
        bool good = true;
        for (int r = l; r < n; ++r)
        {
            balance += s[r] != ')' ? +1 : -1;
            if (balance < 0) good = false;
            prefix[l][r] = good;
        }
    }

    for (int r = 0; r < n; ++r)
    {
        int balance = 0;
        bool good = true;
        for (int l = r; l >= 0; --l)
        {
            balance += s[l] != '(' ? +1 : -1;
            if (balance < 0) good = false;
            suffix[l][r] = good;
        }
    }

    int ans = 0;

    for (int l = 0; l < n; ++l)
    {
        for (int r = l + 1; r < n; r += 2)
        {
            ans += prefix[l][r] && suffix[l][r];
        }
    }

    cout << ans << endl;

    exit(0);
}