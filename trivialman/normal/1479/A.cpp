#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int n, a[N];

int ask(int x) {
    int res;
    cout << "? " << x << endl;
    cin >> res;
    return res;
}

int main() {
    cin >> n;
    a[0] = n + 1, a[n + 1] = n + 1;

    if (n < 3) {
        rep(i, 1, n) a[i] = ask(i);
        rep(i, 1, n) if (a[i] < min(a[i - 1], a[i + 1])) {
            cout << "! " << i << endl;
            return 0;
        }
    } else {
        int l = 0, r = n + 1;
        while (l + 2 < r) {
            int mid = l + r >> 1;
            int x = ask(mid), y = ask(mid + 1);
            if (x < y)
                r = mid + 1;
            else
                l = mid;
        }
        //now l+2==r
        cout << "! " << l + 1 << endl;
    }

    return 0;
}