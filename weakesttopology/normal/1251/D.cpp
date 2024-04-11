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
typedef pair<ll, int> li;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        ll s; cin >> s;

        vii A(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i].f >> A[i].s;

        sort(A.begin(), A.end());

        for (int i = 0; i < n; ++i)
            s -= A[i].f;

        vector<li> V;
        for (int i = 0; i < n / 2; ++i)
            V.pb({A[i].f, i});

        ll ans = A[n / 2].f;
        ll m = A[n / 2].s;
        int c = 0;
        set<li> S;
        for (int i = n / 2; i < n && s > c; ++i)
        {
            c++;
            S.insert({A[i].s, i});
            while (i + 1 < n && A[i + 1].f == ans)
            {
                c++;
                i++;
                S.insert({A[i].s, i});
            }

RESTART:
            m = S.begin()->f;

            ll b = LINF;
            if (i + 1 < n)
                b = A[i + 1].f;

            ll nans = min(ans + s / c, min(m, b));

            s -= c * (nans - ans);
            ans = nans;

            if (not V.empty() && m == ans)
            {
                li p = V.back();
                li q = *S.begin();
                ll diff = (ans - A[q.s].f) - (ans - A[p.s].f);
                if (A[p.s].s > m && s + diff >= 0)
                {
                    S.insert({A[p.s].s, p.s});
                    s += diff;
                    S.erase(S.begin());
                }
                V.pop_back();

                m = S.begin()->f;

                goto RESTART;
            }
        }

        cout << ans << endl;
    }
    exit(0);
}