#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

struct Node{
    int maxx = 0, mini;
    Node() {}
    Node(int val) {
        mini = val;
    }
};

const int MAX_N = 1 << 18, INF = 2e18;
Node t[2 * MAX_N];
int ans[MAX_N];

void relax(int pos) {
    t[pos].mini = min(t[2 * pos].mini, t[2 * pos + 1].mini);
}

void full(int pos, int val) {
    //if (pos == MAX_N + 4) cout << pos << ' ' << val << endl;
    //cout << "!! " << pos << ' ' << val << endl;
    t[pos].maxx = max(t[pos].maxx, val);
    t[pos].mini = max(t[pos].mini, val);
}

void push(int pos) {
    full(2 * pos, t[pos].maxx);
    full(2 * pos + 1, t[pos].maxx);
}

pair <int, int> get_pos(int pos, int l, int r) {
    if (l == r) return {l, t[pos].mini};
    int m = (l + r) / 2;
    push(pos);
    if (t[2 * pos].mini <= t[pos].mini) return get_pos(2 * pos, l, m);
    return get_pos(2 * pos + 1, m + 1, r);
}

void update(int pos, int l, int r, int a, int b, int val) {
    if (l > b || a > r) return;
    if (a <= l && r <= b) {
        full(pos, val);
        return;
    }
    push(pos);
    int m = (l + r) / 2;
    update(2 * pos, l, m, a, b, val);
    update(2 * pos + 1, m + 1, r, a, b, val);
    relax(pos);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t[MAX_N + i] = Node(x);
    }
    for (int i = n; i < MAX_N; i++) {
        t[MAX_N + i] = Node(INF);
    }
    for (int i = MAX_N - 1; i >= 1; i--) relax(i);
    int lst = 0;
    for (int i = 0; i < n; i++) {
        pair <int, int> kek = get_pos(1, 1, MAX_N);
        kek.second = max(kek.second, lst);
        ans[kek.first] = kek.second + p;
        lst = ans[kek.first];
        //cout << kek.first << ' ' << t[1].mini << ' ' << kek.second + p << endl;
        update(1, 1, MAX_N, kek.first, kek.first, INF);
        //cout << kek.first << endl;
        update(1, 1, MAX_N, kek.first + 1, MAX_N, kek.second + p);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}