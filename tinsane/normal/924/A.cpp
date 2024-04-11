#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cerr << #x << " = " << x << endl
#define print_array(arr, len) {cerr << #arr << " = "; for (int i = 0; i < len; i++) cerr << arr[i] << " "; cerr << endl;}
#define print_iterable(it) {cerr << #it << " = "; for (const auto &e : it) cerr << e << " "; cerr << endl;}
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) (void)0
#define print_iterable(it) (void)0
#endif

using ll = long long;

const int N = 105;

int n, m;
char board[N][N];
vector<vector<int>> rows;

bool has_inter(const vector<int>& a, const vector<int>& b)
{
    set<int> in_a(a.begin(), a.end());
    for (int x : b)
        if (in_a.count(x) == 1)
            return true;
    return false;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", board[i]);

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
            if (board[i][j] == '#')
                row.push_back(j);
        rows.push_back(row);
    }

    sort(rows.begin(), rows.end());
    rows.resize(unique(rows.begin(), rows.end()) - rows.begin());

    for (int i = 0; i < (int)rows.size(); i++)
        for (int j = 0; j < (int)rows.size(); j++)
            if (i != j && has_inter(rows[i], rows[j]))
            {
                puts("No");
                return;
            }
    puts("Yes");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}