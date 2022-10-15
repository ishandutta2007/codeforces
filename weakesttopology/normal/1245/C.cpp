#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    string S; cin >> S;
    ll mod = 1e09 + 7;
    int n = S.size();

    for (int i = 0; i < n; ++i)
    {
        char c = S[i];
        if (c == 'w' || c == 'm')
        {
            cout << 0 << endl;
            exit(0);
        }
    }

    vector<ll> dp(n, 1);
    if (n >= 2 && (S[0] == 'u' || S[0] == 'n'))
    {
        dp[1] += S[1] == S[0];
    }

    for (int i = 2; i < n; ++i)
    {
        char c = S[i];
        if (c == 'w' || c == 'm')
        {
            cout << 0 << endl;
            exit(0);
        }
        if (c != 'u' && c != 'n')
            dp[i] = dp[i-1];

        else if (S[i-1] == c)
            dp[i] = (dp[i-1] + dp[i - 2]) % mod;

        else
            dp[i] = dp[i-1];
    }

    cout << dp.back() << endl;

    exit(0);
}