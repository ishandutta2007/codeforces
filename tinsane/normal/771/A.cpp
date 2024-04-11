#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cerr << #x << " = " << x << endl
#define print_array(arr, len) {cerr << #arr << " = "; for(int i = 0; i < len; ++i) cerr << arr[i] << ' '; cerr << endl;}
#define print_iterable(it) {cerr << #it << " = "; for(const auto& e : it) cerr << e << ' '; cerr << endl << endl;}
#define print_2d_array(arr, len1, len2) {cerr << #arr << ':' << endl;\
for(int i = 0; i < len1; ++i, cerr << endl) \
for(int j = 0; j < len2; ++j)\
cerr << arr[i][j] << ' '; \
cerr << endl; }
#define print_endl() cerr << endl
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) (void)0;
#define print_iterable(it) (void)0;
#define print_2d_array(arr, len1, len2) (void)0;
#define print_endl() (void)0
#endif

typedef long long ll;
const int N = 200500;

int n, m;
vector<int> go[N];
bool used[N];
vector<int> comp;

void dfs(int v)
{
    comp.push_back(v);
    used[v] = true;
    for (int to : go[v])
        if (!used[to])
            dfs(to);
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        go[a].push_back(b);
        go[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            comp.clear();
            dfs(i);
            int sz = (int)comp.size();
            for (int v : comp)
                if ((int)go[v].size() != sz - 1)
                {
                    puts("NO");
                    return;
                }
        }

    puts("YES");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}