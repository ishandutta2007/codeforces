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

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        int A[2][2] = { {0, 0}, {0, 0} };
        vi X[2][2];
        vector<string> H;

        set<string> G[2][2];

        for (int i = 0; i < n; ++i)
        {
            string S; cin >> S;
            int x = S[0] - '0', y = S.back() - '0';
            A[x][y]++;
            X[x][y].pb(i);

            H.pb(S);
            G[x][y].insert(S);
        }

        if (A[0][1] == 0 && A[1][0] == 0 && A[0][0] && A[1][1])
            cout << -1 << endl;
        else
        {
            int ans = abs(A[0][1] - A[1][0]) / 2;

            vi I;
            bool x = A[0][1] < A[1][0];
            int c = 0;

            for (int i = 0; i < (int)X[x][!x].size() && c < ans; ++i)
            {
                int index = X[x][!x][i];
                reverse(ALL(H[index]));

                if (G[!x][x].count(H[index]) == 0)
                {
                    c++;
                    I.pb(index);
                }
            }

            if (c < ans)
                cout << -1 << endl << endl;
            else
            {
                cout << ans << endl;
                for (auto i : I)
                    cout << i + 1 << " ";
                cout << endl;
            }
        }
    }
    exit(0);
}