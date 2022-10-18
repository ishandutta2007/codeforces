#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int a, int b) {  // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

int naive(int a, int b) {
    map<pair<int, int>, int> mp;
    queue<pair<int, int>> que;
    que.emplace(a, b);
    mp[que.front()] = 0;
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        if (x == y) {
            return mp[make_pair(x, y)];
        }
        if (!mp.count(make_pair(x + 1, y))) {
            mp[make_pair(x + 1, y)] = mp[make_pair(x, y)] + 1;
            que.emplace(x + 1, y);
        }
        if (!mp.count(make_pair(x, y + 1))) {
            mp[make_pair(x, y + 1)] = mp[make_pair(x, y)] + 1;
            que.emplace(x, y + 1);
        }
        if (!mp.count(make_pair(x | y, y))) {
            mp[make_pair(x | y, y)] = mp[make_pair(x, y)] + 1;
            que.emplace(x | y, y);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        // a = get_rand(1, 100);
        // b = get_rand(1, 100) + a;
        int c = b + (b - a) * 2;
        int ans = b - a;
        for (int y = b; y < c; y++) {
            int x = 0;
            for (int i = 21; i >= 0; i--) {
                if (a & (1 << i)) {
                    if (y & (1 << i)) {
                        x |= 1 << i;
                    } else {
                        for (int j = i + 1; j < 22; j++) {
                            if (a & (1 << j)) {
                                x ^= 1 << j;
                            } else if (y & (1 << j)) {
                                x |= 1 << j;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            ans = min(ans, (y - b) + (x - a) + (x != y));
        }
        cout << ans << '\n';
#ifdef tabr
        if (ans != naive(a, b)) {
            debug(a, b);
            debug(ans, naive(a, b));
            assert(false);
        }
#endif
    }
    return 0;
}