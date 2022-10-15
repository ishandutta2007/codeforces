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
        string S; cin >> S;

        char last = '\n';

        string X;
        vi C;

        for (auto c : S)
        {
            if (c == last)
                C.back()++;
            else
            {
                X.pb(c);
                C.pb(1);
            }

            last = c;
        }

        int ans = 0;

        vi I;

        int n = X.size();
        for (int i = 0, z = 0; i < n; z += C[i], ++i)
        {
            string W = X.substr(i, 5);
            string U = X.substr(i, 3);

            if (W == "twone" && C[i + 1] == 1 && C[i + 3] == 1)
            {
                if (C[i + 2] == 1)
                {
                    ans += 1;
                    I.pb(z + C[i] + C[i + 1]);
                }
                else
                {
                    ans += 2;
                    I.pb(z + C[i]);
                    I.pb(z + C[i] + C[i + 1] + C[i + 2]);
                }

                z += C[i] + C[i + 1] + C[i + 2] + C[i + 3];
                i += 4;
            }
            else if ((U == "one" || U == "two") && C[i + 1] == 1)
            {
                ans += 1;
                I.pb(z + C[i]);
                z += C[i] + C[i + 1];
                i += 2;
            }
        }

        cout << ans << endl;
        for (auto z : I)
            cout << z + 1 << " ";
        cout << endl;
    }
    exit(0);
}