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
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

inline ll dist(pll a, pll b)
{
    return abs(a.f - b.f) + abs(a.s - b.s);
}

int main()
{ _
    int n; cin >> n;

    auto comp = [](ii a, ii b) mutable
    {
        int u = max(a.f, a.s), v = max(b.f, b.s);

        if (u < v)
            return true;
        else if (u == v)
            return mp(a.f, - a.s) < mp(b.f, - b.s);
        else
            return false;
    };

    map<int, vpll> H;
    for (int i = 0; i < n; ++i)
    {
        pll p; cin >> p.f >> p.s;
        H[max(p.f, p.s)].pb(p);
    }

    ii last[2] = { mp(0, 0) };
    ll sum[2] = { 0, 0 };

    for (auto& [k, v] : H)
    {
        sort(ALL(v), comp);
        ii p[2] = { *v.begin(), *v.rbegin() };
        ll d = dist(p[0], p[1]);

        ll temp[2] = { sum[0], sum[1] };

        for (int x = 0; x <= 1; ++x)
            sum[x] = min(
                temp[x] + dist(last[x], p[!x]),
                temp[!x] + dist(last[!x], p[!x])
            ) + d;

        for (int x = 0; x <= 1; ++x)
            last[x] = p[x];
    }

    cout << min(sum[0], sum[1]) << endl;

    exit(0);
}