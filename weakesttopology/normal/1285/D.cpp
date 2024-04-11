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

ll min_xor(ll p, const set<ll>& S)
{
    if (p == -1 || S.size() == 1)
        return 0;

    ll Z = 1LL << p;

    set<ll> B[2];
    for (auto x : S)
    {
        if (x & (1LL << p))
            B[1].insert(x & (Z - 1));
        else
            B[0].insert(x & (Z - 1));
    }

    if (B[0].size() == 0)
        return min_xor(p - 1, B[1]);
    else if (B[1].size() == 0)
        return min_xor(p - 1, B[0]);
    else
    {
        ll X = min_xor(p - 1, B[0]), Y = min_xor(p - 1, B[1]);

        return Z + min(X, Y);
    }
}

int main()
{ _
    int n; cin >> n;
    vll a(n); READ(a);
    sort(ALL(a));

    set<ll> S;
    for (auto x : a)
        S.insert(x);

    ll p = 0;
    while((1LL << (p + 1)) <= a.back())
        p++;

    cout << min_xor(p, S) << endl;

    exit(0);
}