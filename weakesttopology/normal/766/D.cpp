#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
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

class UFDS
{
private:
    vector<int> p, rk, sz;
    int num_disjoint_sets;
public:
    UFDS(int n)
    {
        rk.assign(n, 0);
        p.assign(n, 0);
        for (int i = 0; i < n; ++i)
            p[i] = i;
        num_disjoint_sets = n;
        sz.assign(n, 1);
    }
    int find_set(int i)
    {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }
    bool is_same_set(int i, int j)
    {
        return find_set(i) == find_set(j);
    }
    void union_set(int i, int j)
    {
        int x = find_set(i), y = find_set(j);
        if (x != y)
        {
            --num_disjoint_sets;
            if (rk[x] >= rk[y])
            {
                p[y] = x;
                rk[x] += (rk[x] == rk[y]);
                sz[x] += sz[y];
            }
            else
            {
                p[x] = y;
                sz[y] += sz[x];
            }
        }
    }
    int set_size(int i)
    {
        return sz[find_set(i)];
    }
    int num_sets()
    {
        return num_disjoint_sets;
    }
};

int main()
{ _
    int n, m, q; cin >> n >> m >> q;

    map<string, int> H;
    for (int z = 0; z < n; ++z)
    {
        string a; cin >> a;
        H[a]=z;
    }


    UFDS S(n);
    vi enemy(n, -1);

    for (int j = 0; j < m; ++j)
    {
        int t; cin >> t;
        string x, y; cin >> x >> y;
        int u = S.find_set(H[x]), v = S.find_set(H[y]);

        int eu = enemy[u] != -1 ? S.find_set(enemy[u]) : -1, ev = enemy[v] != -1 ? S.find_set(enemy[v]) : -1;

        if (t == 1 && (eu == -1 || eu != v) && (ev == -1 || ev != u))
        {
            cout << "YES\n";
            S.union_set(u, v);

            if (eu != -1 && ev != -1)
            {
                S.union_set(eu, ev);
                eu = ev = S.find_set(eu);
            }
            else
                eu = ev = max(eu, ev);

            int p = S.find_set(u);
            enemy[p] = eu;
        }
        else if (t == 2 && not S.is_same_set(u, v))
        {
            cout << "YES\n";

            if (eu != -1)
            {
                S.union_set(eu, v);
                v = S.find_set(v);
            }
            if (ev != -1)
            {
                S.union_set(u, ev);
                u = S.find_set(u);
            }

            enemy[u] = S.find_set(v);
            enemy[v] = S.find_set(u);
        }
        else
            cout << "NO\n";
    }

    for (int j = 0; j < q; ++j)
    {
        string x, y; cin >> x >> y;
        int u = S.find_set(H[x]), v = S.find_set(H[y]);

        int eu = enemy[u] != -1 ? S.find_set(enemy[u]) : -1, ev = enemy[v] != -1 ? S.find_set(enemy[v]) : -1;


        if (S.is_same_set(u, v))
            cout << 1 << endl;
        else if (eu == v || ev == u)
            cout << 2 <<  endl;
        else
            cout << 3 << endl;
    }

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/