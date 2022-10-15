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
#define SZ(X) (int)X.size()

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
    int n, m; cin >> n >> m;

    if (n == 3 && m == 0)
    {
        cout << "No\n";
        exit(0);
    }

    vector<set<int>> E(n);
    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; u--; v--;
        E[u].insert(v);
        E[v].insert(u);
    }

    int u = 0;
    for (int v = 1; v < n; ++v)
        if (SZ(E[u]) < SZ(E[v]))
            u = v;

    set<int> B; B.insert(u);
    for (int v = 0; v < n; ++v)
    {
        if (not E[u].count(v) || not E[v].count(u))
            continue;

        set<int> R = E[u]; R.erase(v);
        set<int> S = E[v]; S.erase(u);

        if (R == S)
            B.insert(v);
    }

    for (int v = 0; v < n; ++v)
        if (B.count(v) == 0)
        {
            u = v;
            break;
        }

    set<int> A;
    if (B.count(u) == 0)
    {
        A.insert(u);
        for (int v = 0; v < n; ++v)
        {
            if (not E[u].count(v) || not E[v].count(u))
                continue;

            set<int> R = E[u]; R.erase(v);
            set<int> S = E[v]; S.erase(u);

            if (R == S)
                A.insert(v);
        }
    }

    for (int v = 0; v < n; ++v)
        if (A.count(v) == 0 && B.count(v) == 0)
        {
            u = v;
            break;
        }

    set<int> C;
    if (A.count(u) + B.count(u) == 0)
    {
        C.insert(u);
        for (int v = 0; v < n; ++v)
        {
            if (not E[u].count(v) || not E[v].count(u))
                continue;

            set<int> R = E[u]; R.erase(v);
            set<int> S = E[v]; S.erase(u);

            if (R == S)
                C.insert(v);
        }
    }

    if (SZ(A) + SZ(B) + SZ(C) == n)
    {
        cout << "Yes\n";

        vector<char> X(n, '_');
        for (auto v : A)
            X[v] = 'a';

        if (SZ(B) - 1 == SZ(E[*B.begin()]))
            for (auto v : B)
                X[v] = 'c';
        else
        {
            for (auto v : B)
                X[v] = 'b';
            for (auto v : C)
                X[v] = 'c';
        }

        for (auto x : X)
            cout << x;
        cout << endl;
    }
    else
        cout << "No\n";

    exit(0);
}