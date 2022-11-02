#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    pair<int, int> s = make_pair(0, 0);
    for (int q = 0; q < Q; ++q) {
        char c;
        cin >> c;
        if (c == '+') {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            s.first = max(s.first, x);
            s.second = max(s.second, y);
        } else {
            int h, w;
            cin >> h >> w;
            if (h > w) swap(h, w);
            cout << (s.first <= h && s.second <= w ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}