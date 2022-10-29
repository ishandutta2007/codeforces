#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int n, q, x, y;

int ask(int l, int r) {
    int x;
    cout << "? " << l << " " << r << endl;
    cin >> x;
    return x;
}

int main() {
    cin >> n;
    int l = 1, r = n, sec = ask(l, r);
    while (l < r) {
        if (l + 1 == r) {
            int x = ask(l, r);
            cout << "! " << (x == l ? r : l) << endl;
            return 0;
        } else if (l + 2 == r) {
            int x = ask(l, r), y = ask(l, l + 1);
            if (x == r || x == y) {
                cout << "! " << (y == l ? l + 1 : l) << endl;
                return 0;
            } else {
                cout << "! " << r << endl;
                return 0;
            }
        }

        int mid = l + r >> 1;
        if (sec < l) {
            int x = ask(sec, mid);
            x == sec ? r = mid : l = mid + 1;
        } else if (sec > r) {
            int x = ask(mid + 1, sec);
            x == sec ? l = mid + 1 : r = mid;
        } else {
            if (sec <= mid) {
                x = ask(l, mid);
                x == sec ? r = mid : l = mid + 1;
            } else {
                x = ask(mid + 1, r);
                x == sec ? l = mid + 1 : r = mid;
            }
        }
    }
    cout << "! " << l << endl;
    return 0;
}