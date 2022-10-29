#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
//typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int T, n, x, tot, cnt, ans;
int in[N], out[N], tr[N << 1];
vector<int> ga[N], gb[N];

void add(int x, int val) {
    for (; x <= n * 2; x += x & -x)
        tr[x] += val;
}
int get(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res += tr[x];
    return res;
}

void dfsa(int x) {
    //there will not be numbers between in[x] and out[x], since fa[x] < x in both trees
    //interval change, single node query, can differentiate and use a BIT to do this
    int id = get(in[x]);
    if (id) {
        add(in[id], -id), add(out[id], id);
        add(in[x], x), add(out[x], -x);
    } else {
        cnt++, ans = max(ans, cnt);
        add(in[x], x), add(out[x], -x);
    }

    for (auto u : ga[x])
        dfsa(u);

    add(in[x], -x), add(out[x], x);
    if (id)
        add(in[id], id), add(out[id], -id);
    else
        cnt--;
}

void dfsb(int x) {
    in[x] = ++tot;
    for (auto u : gb[x])
        dfsb(u);
    out[x] = ++tot;
}

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n) ga[i].clear(), gb[i].clear();
        rep(i, 1, 2 * n) tr[i] = 0;

        rep(i, 2, n) scanf("%d", &x), ga[x].PB(i);
        rep(i, 2, n) scanf("%d", &x), gb[x].PB(i);
        tot = 0;
        dfsb(1);
        cnt = ans = 0;
        dfsa(1);
        printf("%d\n", ans);
    }
    return 0;
}