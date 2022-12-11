#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1 << 19;

struct Node{
    int s1 = 0, s2 = 0;
    bool d = 0;
    Node() {}
    Node (int s1, int s2): s1(s1), s2(s2) {}
};

Node t[2 * N];

void relax(int pos) {
    t[pos].s1 = t[2 * pos].s1 + t[2 * pos + 1].s1;
    t[pos].s2 = t[2 * pos].s2 + t[2 * pos + 1].s2;
}

void full(int pos) {
    t[pos].s1 = t[pos].s2 = 0;
    t[pos].d = 1;
}

void push(int pos) {
    if (!t[pos].d) return;
    full(2 * pos);
    full(2 * pos + 1);
    t[pos].d = 0;
}

pair <int, int> get(int pos, int l, int r, int a, int b) {
    if (l > b || a > r) return {0, 0};
    if (a <= l && r <= b) return {t[pos].s1, t[pos].s2};
    int m = (l + r) / 2;
    push(pos);
    auto aa = get(2 * pos, l, m, a, b);
    auto bb = get(2 * pos + 1, m + 1, r, a, b);
    return {aa.first + bb.first, aa.second + bb.second};
}

void set0(int pos, int l, int r, int a, int b) {
    if (l > b || a > r) return;
    if (a <= l && r <= b) {
        full(pos);
        return;
    }
    push(pos);
    int m = (l + r) / 2;
    set0(2 * pos, l, m, a, b);
    set0(2 * pos + 1, m + 1, r, a, b);
    relax(pos);
}

void addval(int pos, int l, int r, int need, int k) {
    if (l == r) {
        t[pos].s1 += k;
        t[pos].s2 += need * k;
        //t[pos] = Node(k, need * k);
        return;
    }
    push(pos);
    int m = (l + r) / 2;
    if (need <= m) addval(2 * pos, l, m, need, k);
    else addval(2 * pos + 1, m + 1, r, need, k);
    relax(pos);
}


signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n;     
    cin >> n;
    int res = 0;
    string s;
    cin >> s;
    int lst = -1;
    for (int i = n - 1; i >= 0; i--) {
        //cout << "!! " << i << ' ' << res << endl;
        if (s[i] == '0') {
            if (lst != -1) {
                for (int j = i + 1; j <= lst; j++) {
                    addval(1, 0, N - 1, j - (i + 1) + 1, 1);
                }
            }
            lst = -1;
            addval(1, 0, N - 1, 0, 1);
            res += t[1].s2;
            continue;
        }
        if (lst == -1) lst = i;
        int len = lst - i + 1;
        int sm = len * (len + 1) / 2;
        //cout << 94 << endl;
        auto x = get(1, 0, N - 1, 0, len - 1);
        //cout << 94 << endl;
        set0(1, 0, N - 1, 0, len - 1);
        //cout << 94 << endl;
        addval(1, 0, N - 1, len, x.first); 
        //cout << 94 << endl;
        res += sm + t[1].s2;
        //cout << t[1].s2 << ' ' << sm << endl;
    }
    cout << res << endl;
    return 0;
}