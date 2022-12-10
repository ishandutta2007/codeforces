#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

const int LOG = 20;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);
const long long INF = (long long) 1e18;


const int N = (int) 1e6 + 100;

struct Tree
{
    pair <long long, int> mx[SZ];
    long long xadd[SZ];

    Tree() : xadd()
    {
        for (int i = 0; i < LEVEL; i++)
            mx[LEVEL + i] = make_pair(-INF, i);
        for (int i = LEVEL - 1; i >= 1; i--)
            update(i);
    }

    void pushV(int v, long long val)
    {
        mx[v].first += val;
        xadd[v] += val;
    }

    void push(int v)
    {
        pushV(2 * v, xadd[v]);
        pushV(2 * v + 1, xadd[v]);
        xadd[v] = 0;
    }

    void update(int v)
    {
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void pushR(int v)
    {
        if (v > 1)
            pushR(v / 2);
        push(v);
    }

    void setVal(int pos, long long val)
    {
        int v = pos + LEVEL;
        pushR(v / 2);
        mx[v] = make_pair(val, pos);
        while (v > 1)
        {
            v /= 2;
            mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        }
    }

    void addVal(int v, int tl, int tr, int l, int r, long long val)
    {
        if (tr < l || r < tl) return;
        if (l <= tl && tr <= r)
        {
            pushV(v, val);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        addVal(2 * v, tl, tm, l, r, val);
        addVal(2 * v + 1, tm + 1, tr, l, r, val);
        update(v);
    }

    pair <long long, int> getMax(int v, int tl, int tr, int l, int r)
    {
        if (tr < l || r < tl) return make_pair(-INF, 0);
        if (l <= tl && tr <= r)
        {
            return mx[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        return max(
                getMax(2 * v, tl, tm, l, r),
                getMax(2 * v + 1, tm + 1, tr, l, r));
    }

    void addVal(int l, int r, long long val)
    {
        addVal(1, 0, LEVEL - 1, l, r, val);
    }

    pair <long long, int> getMax(int l, int r)
    {
        return getMax(1, 0, LEVEL - 1, l, r);
    }

    pair <long long, int> getFirstGreater(pair <long long, int> val)
    {
        int v = 1;
        while (v < LEVEL)
        {
            push(v);
            if (mx[2 * v] > val)
                v = 2 * v;
            else
                v = 2 * v + 1;
        }
        return mx[v];
    }
} tree;

int pos[N], t2d[N];
long long base[N];

void solve() {
    for (int i = 0; i < N; i++)
        base[i] = -INF;
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        char ch[2];
        scanf("%s", ch);
        if (ch[0] == '+')
        {
            int t, d;
            scanf("%d%d", &t, &d);
            //dbg("t = %d, d = %d\n", t, d);
            tree.addVal(t, t, INF + t);
            //dbg("t = %d, d = %d\n", t, d);
            tree.addVal(0, t, d);
            pos[i + 1] = t;
            t2d[t] = d;
            base[t] = t;
        }
        else if (ch[0] == '-')
        {
            int id;
            scanf("%d", &id);
            int t = pos[id];
            int d = t2d[t];
            tree.addVal(0, t, -d);
            tree.addVal(t, t, -t - INF);
            base[t] = -INF;
        }
        else if (ch[0] == '?')
        {
            int t;
            scanf("%d", &t);
            dbg("t = %d\n", t);
            pair <long long, int> lft = tree.getMax(0, t);
            dbg("lft : %lld, %d\n", lft.first, lft.second);
            if (lft.first < 0)
            {
                printf("0\n");
                continue;
            }
            pair <long long, int> pp = tree.getMax(t + 1, t + 1);
            long long ts = -(pp.first - base[t + 1]) + (lft.first - lft.second);
            long long ans = lft.second + ts - t;
            if (ans < 0)
                ans = 0;
            printf("%lld\n", ans);
        }
        else throw;
    }
}

// dbg.txt
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}