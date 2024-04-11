#include <bits/stdc++.h>
#define int long long

using namespace std;

const int K = 60;

bool ch(int a, int pos) {
    return (a & (1ll << pos));
}

void find_kth(int k, int &a, int &b, int &c) {
    int head = -1;
    for (int s = 0; s < K; s += 2) {
        int cnt = (1ll << s);
        if (k >= cnt) {
            k -= cnt;
        } else {
            head=  s;
            break;
        }
    }
    a = (1ll << head);
    b = (2ll << head);
    c = (3ll << head);
    a += k;
    for (int s = head - 2; s >= 0; s -= 2) {
        if (!ch(a, s) && !ch(a, s + 1)) continue;
        if (ch(a, s) && !ch(a, s + 1)) {
            b += (2ll << s);
            c += (3ll << s);
        }
        if (!ch(a, s) && ch(a, s + 1)) {
            b += (3ll << s);
            c += (1ll << s);
        }
        if (ch(a, s) && ch(a, s + 1)) {
            b += (1ll << s);
            c += (2ll << s);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    n--;
    int a, b, c;
    find_kth(n / 3, a, b, c);
    if (n % 3 == 0) cout << a << "\n";
    if (n % 3 == 1) cout << b << "\n";
    if (n % 3 == 2) cout << c << "\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}