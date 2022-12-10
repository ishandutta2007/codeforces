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
const int K = 6;

int n, k;
vector<int> go[N];
bool blocked[N];
int tsize[N];
int cnt[K];
ll ans;

void calc_size(int v, int p)
{
    tsize[v] = 1;
    for (int to : go[v])
    {
        if (to == p || blocked[to])
            continue;
        calc_size(to, v);
        tsize[v] += tsize[to];
    }
}

int get_root(int v, int p, int full_sz)
{
    for (int to : go[v])
    {
        if (to == p || blocked[to])
            continue;
        if (2 * tsize[to] > full_sz)
            return get_root(to, v, full_sz);
    }
    return v;
}

void dfs_ans(int v, int p, int d, int outer)
{
    ans += (ll)(d / k) * outer;
    int r1 = d % k;
    for (int r2 = 0; r2 < k; r2++)
    {
        int s = r1 + r2;
        if (0 < s && s <= k)
            ans += cnt[r2];
        if (k < s)
            ans += 2 * cnt[r2];
    }
    for (int to : go[v])
    {
        if (to == p || blocked[to])
            continue;
        dfs_ans(to, v, d + 1, outer);
    }
}

void dfs_count(int v, int p, int d)
{
    cnt[d % k]++;
    for (int to : go[v])
    {
        if (to == p || blocked[to])
            continue;
        dfs_count(to, v, d + 1);
    }
}

void centroid(int sv)
{
    calc_size(sv, -1);
    int root = get_root(sv, -1, tsize[sv]);
    calc_size(root, -1);

    memset(cnt, 0, sizeof(cnt));
    cnt[0]++;

    for (int to : go[root])
    {
        if (blocked[to])
            continue;
        dfs_ans(to, root, 1, tsize[root] - tsize[to]);
        dfs_count(to, root, 1);
    }

    blocked[root] = true;
    for (int to : go[root])
    {
        if (blocked[to])
            continue;
        centroid(to);
    }
}

void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        go[a].push_back(b);
        go[b].push_back(a);
    }

    centroid(0);

    printf("%lld\n", ans);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}