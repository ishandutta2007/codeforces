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
    int num_sets() { return num_disjoint_sets; }
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
};

int main()
{ _
    int n, m; cin >> n >> m;

    vector<set<int>> E(n + 1);
    UFDS U(n + 1);
    for (int j = 0; j < m; ++j)
    {
        int a, b; cin >> a >> b;
        E[a].insert(b);
        E[b].insert(a);
    }

    vector<int> C(n + 1, 0);

    for (int k = 1; k <= 3; ++k)
    {
        int x = 1;
        while (x <= n && C[x])
            x++;
        if (x == n + 1)
        {
            cout << -1 << endl;
            exit(0);
        }
        C[x] = k;

        for (int y = 1; y <= n; ++y)
        {
            if (!E[x].count(y))
            {
                U.union_set(x, y);
                C[y] = k;
            }
        }
    }

    map<int, int> set_sizes;
    for (int x = 1; x <= n; ++x)
    {
        for (auto v : E[x])
            if (U.is_same_set(v, x))
            {
                cout << -1 << endl;
                exit(0);
            }
        set_sizes[U.find_set(x)] = U.set_size(x);
    }


    if (U.num_sets() != 4)
    {
        cout << -1 << endl;
        exit(0);
    }

    ll num_edges = 0;
    for (auto [k, v] : set_sizes)
    {
        if (k == 0)
            continue;
        for (auto [k1, v1] : set_sizes)
        {
            if (k1 == 0 || k1 == k)
                continue;

            num_edges += v * v1;
        }
    }
    num_edges /= 2;

    if (m != num_edges)
    {
        cout << -1 << endl;
        exit(0);
    }

    for (int i = 1; i <= n; ++i)
        cout << C[i] << " ";

    cout << endl;
    exit(0);
}