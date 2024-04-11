#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Node{
    int sm = 0, mini, maxi, d = -1;
    Node() {}
    Node(int x): sm(x), mini(x), maxi(x) {}
};

const int N = 1 << 18;
Node t[2 * N];
int a[N];

void relax(int pos) {
    t[pos].sm = t[2 * pos].sm + t[2 * pos + 1].sm;
    t[pos].mini = t[2 * pos + 1].mini;
    t[pos].maxi = t[2 * pos].maxi;
}

void full(int pos, int len, int val) {
    t[pos].sm = len * val;
    t[pos].mini = t[pos].maxi = t[pos].d = val;
}

void push(int pos, int len) {
    if (t[pos].d == -1)
        return;
    full(2 * pos, len / 2, t[pos].d);
    full(2 * pos + 1, len / 2, t[pos].d);
    t[pos].d = -1;
}

void set_maxi(int pos, int l, int r, int a, int b, int val) {
    if (a > r || l > b)
        return;
    if (a <= l && r <= b) {
        if (t[pos].mini >= val)
            return;
        if (t[pos].maxi <= val) {
            full(pos, r - l + 1, val);
            return;
        }
    }
    push(pos, r - l + 1);
    int m = (l + r) / 2;
    set_maxi(2 * pos, l, m, a, b, val);
    set_maxi(2 * pos + 1, m + 1, r, a, b, val);
    relax(pos);
}

pair <int, int> eat_from(int pos, int l, int r, int a, int b, int rest) {
    if (a > r || l > b)
        return {-1, -1};
    //if (r - l < 10) cout << l << ' ' << r << ' ' << rest << endl;
    if (a <= l && r <= b) {
        if (l == r) {
            if (rest >= t[pos].sm) {
                return {r, rest - t[pos].sm};
            } else {
                return {l - 1, rest};
            }
        }
        int m = (l + r) / 2;
        push(pos, r - l + 1);
        if (t[2 * pos].sm <= rest)
            return eat_from(2 * pos + 1, m + 1, r, a, b, rest - t[2 * pos].sm);
        else 
            return eat_from(2 * pos, l, m, a, b, rest);
    }
    push(pos, r - l + 1);
    int m = (l + r) / 2;
    auto p1 = eat_from(2 * pos, l, m, a, b, rest);
    if (p1.first == -1)
        return eat_from(2 * pos + 1, m + 1, r, a, b, rest);
    if (p1.first == m) {
        //if (r - l < 10) cout << "Kek! " << l << ' ' << r << endl;
        auto p2 = eat_from(2 * pos + 1, m + 1, r, a, b, p1.second);
        if (p2.first == -1)
            return p1;
        return p2;
    }
    //if (r - l < 10) cout << "Kek! " << l << ' ' << r << endl;
    return p1;
}

int get_start_pos(int pos, int l, int r, int rest) {
    if (l == r) {
        if (rest >= t[pos].sm) {
            return l;
        } else {
            return l + 1;
        }
    }
    int m = (l + r) / 2;
    push(pos, r - l + 1);
    if (t[2 * pos].mini <= rest)
        return get_start_pos(2 * pos, l, m, rest);
    else 
        return get_start_pos(2 * pos + 1, m + 1, r, rest);
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t[N + i - 1] = Node(a[i]);
    }
    for (int i = N - 1; i >= 1; i--) relax(i);
    for (int i = 0; i < q; i++) {
        int tp, x, y;
        cin >> tp >> x >> y;
        if (tp == 1) {
            set_maxi(1, 1, N, 1, x, y);
        } else {
            int cur = y;
            int ans = 0;
            int pos = x;
            while (cur > 0) {
                pos = max(pos, get_start_pos(1, 1, N, cur));
                if (pos > n)
                    break;
                auto p1 = eat_from(1, 1, N, pos, n, cur);
                //cout << pos << ' ' << p1.second << ' ' << p1.first << endl;
                cur = p1.second;
                ans += p1.first - pos + 1;
                pos = p1.first + 1;
                //cout << cur << endl;
            }
            cout << ans << "\n";
        }
        //if (i == 0)
            //break;
    }
    return 0;
}