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

ll dist(pll a, pll b)
{
    return abs(a.f - b.f) + abs(a.s - b.s);
}

int main()
{ _
    int n; cin >> n;
    pll s; cin >> s.f >> s.s;

    set<pll> S;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            S.insert(mp(s.f + i, s.s + j));
    S.erase(s);

    map<pll, int> H;

    for (int i = 0; i < n; ++i)
    {
        ii P; cin >> P.f >> P.s;

        for (auto Q : S)
            if (dist(P, Q) + dist(Q, s) == dist(P, s))
                H[Q]++;
    }

    int m = -1;
    ii P;

    for (auto [k, v] : H)
        if (v > m)
        {
            P = k;
            m = v;
        }

    cout << m << endl << P.f << " " << P.s << endl;

    exit(0);
}