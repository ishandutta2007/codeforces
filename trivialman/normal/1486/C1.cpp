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
    int l = 1, r = n;
    while (l < r) {
        if (l + 1 == r) {
            int x = ask(l, r);
            cout << "! " << (x == l ? r : l) << endl;
            return 0;
        } else if (l + 2 == r) {
            int x = ask(l, r), y = ask(l, l + 1);
            if (x == r || x == y) {
                r = l + 1;
                continue;
            } else {
                cout << "! " << r << endl;
                return 0;
            }
        }

        int mid = l + r >> 1;
        int x = ask(l, r), y;
        if (x <= mid) {
            y = ask(l, mid);
            if (x == y)
                r = mid;
            else
                l = mid + 1;
        } else {
            y = ask(mid + 1, r);
            if (x == y)
                l = mid + 1;
            else
                r = mid;
        }
    }
    cout << "! " << l << endl;
    return 0;
}