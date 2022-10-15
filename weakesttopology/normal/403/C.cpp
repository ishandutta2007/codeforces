#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int** A;
int n;
vi dfs_num, dfs_low, S, visited;
int dfs_counter = 0;

int scc = 0;

const int UNVISITED = -1;

void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = dfs_counter++;
    S.push_back(u);
    visited[u] = 1;

    for (int v = 0; v < n; ++v)
    {
        if (u == v || A[u][v] == 0)
            continue;

        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);

        if (visited[v]) // if v is part of current SCC
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u])
    {
        scc++;
        while (1)
        {
            int v = S.back(); S.pop_back();
            visited[v] = 0;
            if (u == v) break;
        }
    }
}

int main()
{ _
    cin >> n;

    int* mem = new int[n * n];

    A = new int*[n];

    for (int i = 0; i < n; ++i)
    {
        A[i] = mem + i * n;
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    }

    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, 0);
    visited.assign(n, 0);
    dfs_counter = 0;
    tarjanSCC(n / 2);

    if (scc == 1 && dfs_counter == n)
        cout << "YES\n";
    else
        cout << "NO\n";

    exit(0);
}