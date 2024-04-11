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

int main()
{ _
    int n, m; cin >> n >> m;
    vector<set<int>> E(n);

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v;
        u--; v--;

        E[u].insert(v);
        E[v].insert(u);
    }

    if (m == 0)
    {
        cout << 0 << endl;
        exit(0);
    }

    set<int> LEFT;
    for (int i = 0; i < n; ++i)
        LEFT.insert(i);

    int c = 0;

    while (not LEFT.empty())
    {
        c++;
        queue<int> Q;
        auto iter = LEFT.begin();
        Q.push(*iter);
        LEFT.erase(iter);

        while (not Q.empty())
        {
            int u = Q.front(); Q.pop();

            set<int> D;
            for (auto x : LEFT)
                if (E[u].count(x) == 0)
                    D.insert(x);

            for (auto x : D)
            {
                LEFT.erase(x);
                Q.push(x);
            }
        }
    }

    cout << c - 1 << endl;

    exit(0);
}