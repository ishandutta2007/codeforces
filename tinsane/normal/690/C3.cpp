#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 400500;
const int SZ = 1 << 19;
const int INF = (int)1e9;

struct SegTree
{
    int t[2 * SZ];
    int flag[2 * SZ];

    SegTree()
    {
        fill(t, t + 2 * SZ, -INF);
        fill(flag, flag + 2 * SZ, 0);
    }

    void apply(int v, int val)
    {
        t[v] += val;
        flag[v] += val;
    }

    void push(int v)
    {
        apply(2 * v, flag[v]);
        apply(2 * v + 1, flag[v]);
        flag[v] = 0;
    }

    void update(int v)
    {
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    void add(int v, int l, int r, int a, int b, int val)
    {
        if (a > r || b < l)
            return;
        if (a <= l && r <= b)
        {
            apply(v, val);
            return;
        }
        push(v);
        int m = (l + r) / 2;
        add(2 * v, l, m, a, b, val);
        add(2 * v + 1, m + 1, r, a, b, val);
        update(v);
    }

    void add(int a, int b, int val)
    {
        add(1, 0, SZ - 1, a, b, val);
    }

    int get_max(int v, int l, int r, int a, int b)
    {
        if (a > r || b < l)
            return -2 * INF;
        if (a <= l && r <= b)
            return t[v];
        push(v);
        int m = (l + r) / 2;
        return max(get_max(2 * v, l, m, a, b),
            get_max(2 * v + 1, m + 1, r, a, b));
    }

    int get_max(int a, int b)
    {
        return get_max(1, 0, SZ - 1, a, b);
    }

    int get(int a)
    {
        return get_max(a, a);
    }

    void set(int a, int val)
    {
        add(a, a, val - get(a));
    }
};

int n;
vector<int> go[N];
vector<int> rgo[N];
pair<int, int> query[N];
int tin[N], tout[N], timer;
int par[N];
int pos_in_trav[N], trav_sz;
int tree_size[N];
SegTree tree;
int center;

void add_edge(int a, int b)
{
    go[a].push_back(b);
    go[b].push_back(a);
}

void dfs_init(int v, int p)
{
    tin[v] = timer++;
    par[v] = p;
    tree_size[v] = 1;
    pos_in_trav[v] = trav_sz++;
    for (int to : go[v])
    {
        if (to == p)
            continue;
        dfs_init(to, v);
        tree_size[v] += tree_size[to];
    }
    tout[v] = timer++;
}

bool is_ancestor(int p, int v)
{
    return tin[p] <= tin[v] && tout[v] <= tout[p];
}

int get_diam()
{
    return tree.get_max(0, n - 1);
}

void move_center_down(int v)
{
    int l = pos_in_trav[v];
    int r = l + tree_size[v] - 1;
    tree.add(l, r, -1);
    tree.add(0, l - 1, 1);
    tree.add(r + 1, n - 1, 1);
    center = v;
}

void move_center_up(int v)
{
    int l = pos_in_trav[v];
    int r = l + tree_size[v] - 1;
    tree.add(l, r, 1);
    tree.add(0, l - 1, -1);
    tree.add(r + 1, n - 1, -1);
    center = par[v];
}

int get_son(int v, int who)
{
    /*
    cout << "SONS " << endl;
    for (int to : rgo[v])
        cout << to << " " << tin[to] << " ; ";
    cout << tin[who] << endl;
    cout << endl;
    */
    int l = -1, r = (int)rgo[v].size();
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (tin[rgo[v][m]] <= tin[who])
            l = m;
        else
            r = m;
    }
    //cout << "R " << r << endl;
    return rgo[v][l];
}

void add_vertex(int v, bool intermid)
{
    /*
    cout << "INFO" << endl;
    for (int i = 0; i < n; i++)
        cout << tree.get(pos_in_trav[i]) << endl;
    cout << endl;

    cout << "ADD " << v << " CENTER " << center << endl;
    */
    tree.set(pos_in_trav[v], tree.get(pos_in_trav[par[v]]) + 1);
    if (intermid)
        return;

    int diam = get_diam();
    if (is_ancestor(center, v))
    {
        int son = get_son(center, v);
        //cout << "SON " << son << endl;
        move_center_down(son);
        if (get_diam() > diam)
            move_center_up(son);
    }
    else
    {
        int old_c = center;
        move_center_up(center);
        if (get_diam() > diam)
            move_center_down(old_c);
    }
    //cout << "END CENTER " << center << endl;
}

void solve()
{
    scanf("%d", &n);
    int vcnt = n;
    for (int v = 1; v < n; v++)
    {
        int p;
        scanf("%d", &p);
        p--;
        int mid = vcnt++;
        add_edge(p, mid);
        add_edge(mid, v);
        query[v] = make_pair(mid, v);
    }
    int old_n = n;
    n = vcnt;

    dfs_init(0, -1);
    center = 0;
    tree.set(pos_in_trav[0], 0);

    for (int v = 0; v < n; v++)
        for (int to : go[v])
            if (to != par[v])
                rgo[v].push_back(to);

    for (int i = 1; i < old_n; i++)
    {
        add_vertex(query[i].first, true);
        add_vertex(query[i].second, false);
        printf("%d ", get_diam());
    }
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}