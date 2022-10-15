#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll mod = 1e9 + 7;

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int x; cin >> x;
        string S; cin >> S;
        ll L = S.size();

        if (S.size() == 1)
        {
            cout << 1 << endl;
            continue;
        }

        for (int l = 0; l + 1 < (int)S.size() && (int)S.size() <= x; ++l)
        {
            int w = S.size();
            for (int z = 1; z < S[l] - '0'; ++z)
                S.append(S.substr(l + 1, w - l - 1));
        }

        for (int l = 1; l <= x; ++l)
            L = (L + (L - ll(l)) * ll(S[l - 1] - '0' - 1)) % mod;

        cout << (L + mod) % mod << endl;
    }
    exit(0);
}