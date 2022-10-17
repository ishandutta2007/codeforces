#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9 + 10;
ll const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-6;

#define f first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mk make_pair
#define fro for
#define itn int
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

int color[MAXN], n, from, to, max1;
bool used[MAXN];
vector<vector<int> > Vec;

void dfs(int v, int c, int prev)
{
    used[v] = true;
    color[v] = c;
    max1 = max(max1, c);
    int k = 1;
    fore(i, Vec[v].size())
    {
        while (k == c || k == prev) k++;
        if (!used[Vec[v][i]])
        {
            dfs(Vec[v][i], k, c);
            k++;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    Vec.resize(n + 1);
    for(int i = 1; i < n; i++)
    {
        cin >> from >> to;
        Vec[from].pb(to);
        Vec[to].pb(from);
    }

    used[1] = true;
    dfs(1, 1, 0);
    cout << max1 << endl;
    forn(i, n) cout << color[i] << " ";





    return 0;
}