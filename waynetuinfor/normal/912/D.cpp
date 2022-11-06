#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const short dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int n, m, r;

struct grid {
    int x, y;
    long long operator()() const {
        int up = max(1, x - r + 1), down = min(n, x + r - 1);
        int left = max(1, y - r + 1), right = min(m, y + r - 1);
        return (down - up - r + 2) * (right - left - r + 2);
    }
    bool operator<(const grid &rhs) const { return operator()() == rhs() ? make_pair(x, y) < make_pair(rhs.x, rhs.y) : operator()() < rhs(); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    priority_queue<grid> pq;
    set<grid> used;
    int k; cin >> n >> m >> r >> k;
    used.insert((grid){ (n + 1) / 2, (m + 1) / 2 });
    pq.push((grid){ (n + 1) / 2, (m + 1) / 2 });
    long long now = 0;
    int rem = k;
    while (k--) {
        grid t = pq.top(); pq.pop();
        // if (used.find(t) != used.end()) continue;
        // cout << t.x << ' ' << t.y << endl;
        // cout << t() << endl;
        now += t();
        // used.insert(t);
        for (int i = 0; i < 4; ++i) {
            int tx = t.x + dx[i], ty = t.y + dy[i];
            // cout << "tx = " << tx << " ty = " << ty << endl;
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
                if (used.find((grid){ tx, ty }) == used.end()) {
                    // cout << "push tx = " << tx << " ty = " << ty << endl;
                    pq.push((grid){ tx, ty });
                    used.insert((grid){ tx, ty });
                }
            }
        }
    }
    cout << fixed << setprecision(20) << 1.0 * now / (n - r + 1) / (m - r + 1) << endl;
    return 0;
}