#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;

int nxt(int pos, int val = 1) {
    pos += val;
    while (pos > n)
        pos -= n;
    return pos;
}

int prv(int pos, int val = 1) {
    pos -= val;
    while (pos <= 0)
        pos += n;
    return pos;
}

void solve_small() {
    for (int i = 1; i <= n + 10; i++) {
        cout << "? 1" << endl;
        int x;
        cin >> x;
    }
    for (int i = 1; i <= n; i++) {
        cout << "? " << i << endl;
        int x;
        cin >> x;
        if (x == k) {
            cout << "? " << nxt(i) << endl;
            int xx;
            cin >> xx;
            if (xx > k) {
                cout << "! " << i << endl;
                exit(0);
            }
        }
    }
}

void solve_big() {
    int tm = -1;
    int sq = sqrt(n);
    for (int i = 1; i <= sq + 3; i++) {
        assert(tm < 998);
        tm++;
        cout << "? 1" << endl;
        int x;
        cin >> x;
    }
    int cur = 1;
    bool lst = 0;
    while (1) {
        assert(tm < 998);
        cout << "? " << cur << endl;
        tm++;
        int x;
        cin >> x;
        if (x > k) {
            lst = 1;
        } else {
            if (lst) {
                cur = prv(cur, sq);
                break;
            }
            lst = 0;
        }
        cur = nxt(cur, sq);
    }
    while (1) {
        assert(tm < 998);
        cout << "? " << cur << endl;
        tm++;
        int x;
        cin >> x;
        if (x <= k) {
            cur = prv(cur);
            break;
        }
        cur = nxt(cur, 2);
    }
    cur = prv(cur, tm);
    cout << "! " << cur << endl;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if (n <= 300)
        solve_small();
    else
        solve_big();
    return 0;
}