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
    int n, m; cin >> n >> m;

    vii E(m);
    for (int j = 0; j < m; ++j)
    {
        cin >> E[j].f >> E[j].s;
        --E[j].f, --E[j].s;
    }

    vector<UFDS> components[2] = { vector<UFDS>(m, UFDS(n)), vector<UFDS>(m, UFDS(n)) };

    components[0][0].union_set(E[0].f, E[0].s);

    for (int j = 1; j < m; ++j)
    {
        components[0][j] = components[0][j - 1];
        components[0][j].union_set(E[j].f, E[j].s);
    }

    components[1][m - 1].union_set(E[m - 1].f, E[m - 1].s);

    for (int j = m - 2; j >= 0; --j)
    {
        components[1][j] = components[1][j + 1];
        components[1][j].union_set(E[j].f, E[j].s);
    }

    int k; cin >> k;

    for (int z = 0; z < k; ++z)
    {
        int l, r; cin >> l >> r; --l, --r;

        if (l == 0 && r == m - 1)
            cout << n << endl;
        else if (l == 0)
            cout << components[1][r + 1].num_sets() << endl;
        else if (r == m - 1)
            cout << components[0][l - 1].num_sets() << endl;
        else
        {
            UFDS L = components[0][l - 1], R = components[1][r + 1];
            for (int u = 0; u < n; ++u)
                L.union_set(u, R.find_set(u));

            cout << L.num_sets() << endl;
        }
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