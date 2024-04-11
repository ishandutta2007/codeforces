#include <bits/stdc++.h>
using namespace std;

int ans, qc;

void prepare() {
#ifdef LOCAL
    ans = rand() % 1000000000 + 1;
    // ans = 1;
    qc = 0;
#endif
}

bool query(int x, int y) {
#ifdef LOCAL
    ++qc;
    assert(0 <= x <= 2000000000);
    assert(0 <= y <= 2000000000);
    if ((x % ans) >= (y % ans)) return true;
    else return false;
#else
    cout << "? " << x << ' ' << y << endl;
    string res; cin >> res;
    return res[0] == 'x';
#endif
}

void answer(int x) {
#ifdef LOCAL
    cout << "x = " << x << " ans = " << ans << endl;
    cout << "qc = " << qc << endl;
    assert(x == ans);
    assert(qc <= 60);
#else
    cout << "! " << x << endl;
#endif
}

int main() {
    srand(clock() + time(0));
    string s;
#ifdef LOCAL
    int iter = 1000;
    while (iter--) {
#else
    while (cin >> s) {
#endif
        if (s == "end") break;
        prepare();
        if (query(0, 1)) {
            answer(1);
            continue;
        }
        int x = 1;
        while (x <= 1000000000) {
            bool res = query(x, 2 * x);
            if (res) break;
            x *= 2;
        }
#ifdef LOCAL
        assert(x < ans && 2 * x >= ans);
#endif
        int x2 = x + x;
        for (int d = 30; d >= 0; --d) {
            int y = x + (1 << d);
            if (y >= x2) continue;
            bool res = query(x, y);
            if (!res) 
                x += (1 << d);
        }
        answer(x + 1);
    }
    return 0;
}