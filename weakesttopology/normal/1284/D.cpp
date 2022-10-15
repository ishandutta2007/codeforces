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
#define SZ(X) (int)X.size();

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
    int n; cin >> n;

    vi sa(n), ea(n), sb(n), eb(n);
    for (int i = 0; i < n; ++i)
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];

    vii E, F;
    for (int i = 0; i < n; ++i)
    {
        E.pb(mp(sa[i], - (i + 1)));
        E.pb(mp(ea[i], i + 1));

        F.pb(mp(sb[i], - (i + 1)));
        F.pb(mp(eb[i], i + 1));
    }
    sort(ALL(E));
    sort(ALL(F));

    string ans = "YES";

    multiset<int> s, e;
    for (auto [x, i] : E)
    {
        bool enter = i < 0;
        if (i < 0)
            i *= -1;
        i--;

        if (enter)
        {
            s.insert(sb[i]);
            e.insert(eb[i]);
        }
        else
        {
            s.erase(s.find(sb[i]));
            e.erase(e.find(eb[i]));
        }

        if (s.size() && *e.begin() < *s.rbegin())
            ans = "NO";
    }

    for (auto [x, i] : F)
    {
        bool enter = i < 0;
        if (i < 0)
            i *= -1;
        i--;

        if (enter)
        {
            s.insert(sa[i]);
            e.insert(ea[i]);
        }
        else
        {
            s.erase(s.find(sa[i]));
            e.erase(e.find(ea[i]));
        }

        if (s.size() && *e.begin() < *s.rbegin())
            ans = "NO";
    }

    cout << ans << endl;

    exit(0);
}