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
    int m; cin >> m;
    while (m--)
    {
        ll n, T, a, b; cin >> n >> T >> a >> b;
        vi D(n); READ(D);
        vi t(n); READ(t);

        int easy = 0, hard = 0;

        vpll P(n);
        for (int i = 0; i < n; ++i)
        {
            easy += D[i] == 0;
            hard += D[i] == 1;

            P[i] = {t[i], D[i]};
        }
        sort(ALL(P));

        ll M = 0, pre_easy = 0, pre_hard = 0;
        for (int i = 0; i < n && a * pre_easy + b * pre_hard <= T; ++i)
        {
            while (i < n && a * pre_easy + b * pre_hard >= P[i].f)
            {
                if (P[i].s)
                    pre_hard++;
                else
                    pre_easy++;
                i++;
            }

            ll x = a * pre_easy + b * pre_hard;

            if (x > T)
                break;
            if (i == n)
            {
                M = n;
                break;
            }

            ll max_easy = min((P[i].f - 1 - x) / a, easy - pre_easy);
            ll max_hard = min((P[i].f - 1 - x - a * max_easy) / b, hard - pre_hard);
            M = max(M, pre_easy + pre_hard + max_easy + max_hard);

            if (P[i].s)
                pre_hard++;
            else
                pre_easy++;
        }

        if (a * easy + b * hard <= T)
            M = n;

        cout << M << endl;
    }
    exit(0);
}