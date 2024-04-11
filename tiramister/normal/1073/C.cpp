#include <iostream>
#include <cmath>
#include <map>

using namespace std;

map<char, pair<int, int>> dir = {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'L', {-1, 0}},
    {'R', {1, 0}}};

int main() {
    int n;
    string s;
    cin >> n >> s;

    int x, y;
    cin >> x >> y;
    if (abs(x + y) % 2 != n % 2 || abs(x) + abs(y) > n) {
        cout << -1 << endl;
        return 0;
    }

    pair<int, int> fore[n + 1];  // [1...i]
    fore[0] = make_pair(0, 0);
    for (int i = 1; i <= n; ++i) {
        fore[i].first = fore[i - 1].first + dir[s[i - 1]].first;
        fore[i].second = fore[i - 1].second + dir[s[i - 1]].second;
    }

    pair<int, int> back[n + 2];  // [i...n]
    back[n + 1] = make_pair(x, y);
    for (int i = n; i >= 1; --i) {
        back[i].first = back[i + 1].first - dir[s[i - 1]].first;
        back[i].second = back[i + 1].second - dir[s[i - 1]].second;
    }

    int ans = n;
    for (int l = 0; l <= n; ++l) {
        // [1...l] + [ok...n]
        int ng = l, ok = n + 2;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            int dx = back[mid].first - fore[l].first;
            int dy = back[mid].second - fore[l].second;
            if (abs(dx) + abs(dy) <= mid - l - 1) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (ok > n + 1) continue;
        ans = min(ans, ok - l - 1);
    }
    cout << ans << endl;
    return 0;
}