#include <iostream>
#define int long long

using namespace std;

struct Node{
    int mini, pos, d = 0;
    Node() {}
    Node(int mini, int pos): mini(mini), pos(pos) {}
};

const int N = 1 << 18, INF = 1e18;
int a[N], res[N];
Node t[2 * N];

void relax(int pos) {
    t[pos].mini = min(t[2 * pos].mini, t[2 * pos + 1].mini);
    if (t[2 * pos].mini == t[pos].mini) t[pos].pos = t[2 * pos].pos;
    if (t[2 * pos + 1].mini == t[pos].mini) t[pos].pos = t[2 * pos + 1].pos;
}

void full(int pos, int d) {
    t[pos].mini += d;
    t[pos].d += d;
}

void push(int pos) {
    full(2 * pos, t[pos].d);
    full(2 * pos + 1, t[pos].d);
    t[pos].d = 0;
}

void rec(int pos, int l, int r, int a, int b, int d) {
    if (l > b || a > r) return;
    if (a <= l && r <= b) {
        full(pos, d);
        return;
    }
    push(pos);
    int m = (l + r) / 2;
    rec(2 * pos, l, m, a, b, d);
    rec(2 * pos + 1, m + 1, r, a, b, d);
    relax(pos);
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        t[N + i - 1] = Node(a[i], i);
        //cout << a[i] << ' ' << i << endl;
    }
    for (int i = n + 1; i <= N; i++) {
        t[N + i - 1] = Node(INF, -1);
    }
    for (int i = N - 1; i >= 1; i--) relax(i);
    //cout << t[1].pos << ' ' << t[1].mini << endl;
    for (int i = 1; i <= n; i++) {
        int pos = t[1].pos;
        res[pos] = i;
        //cout << pos << ' ' << t[1].mini << endl;
        rec(1, 1, N, pos, pos, INF);
        rec(1, 1, N, pos + 1, N, -i);
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    return 0;
}