#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;
const int N = 1 << 20, INF = 1e18;

/*struct monstr{
    int x, y, z;
    monstr() {}
    monstr(int x, int y, int z): x(x), y(y), z(z) {}
};*/

struct Node{
    int maxi = -INF, d = 0;
    Node() {}
};

vector <pair <int, int>> add_m[N];
Node t[2 * N];
int check[N];

void full(int pos, int d) {
    t[pos].maxi += d;
    t[pos].d += d;
}

void push(int pos) {
    full(2 * pos, t[pos].d);
    full(2 * pos + 1, t[pos].d);
    t[pos].d = 0;
}

void relax(int pos) {
    t[pos].maxi = max(t[2 * pos].maxi, t[2 * pos + 1].maxi);
}

void upd(int pos, int l, int r, int a, int b, int val) {
    if (a > r || l > b) return;
    if (a <= l && r <= b) {
        full(pos, val);
        return;
    }
    push(pos);
    int m = (l + r) / 2;
    upd(2 * pos, l, m, a, b, val);
    upd(2 * pos + 1, m + 1, r, a, b, val);
    relax(pos);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i < N; i++) check[i] = -INF;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t[N + a - 1].maxi = max(t[N + a - 1].maxi, -b);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        check[a] = max(check[a], -b);
    }
    for (int i = 0; i < p; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add_m[y].push_back({x, z});
    }
    for (int i = N - 1; i >= 1; i--) relax(i);
    int res = -INF;
    for (int i = 1; i < N; i++) {
        res = max(res, check[i] + t[1].maxi);
        for (pair <int, int> elem : add_m[i]) upd(1, 1, N, elem.first + 1, N, elem.second);
    }
    cout << res << endl;
}