#include <iostream>
#include <set>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair <int, int> p[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    p[n] = p[0];
    set <pair <int, int>> s;
    for (int i = 0; i < n; i++) {
        int x = p[i + 1].first - p[i].first;
        int y = p[i + 1].second - p[i].second;
        if (s.find(make_pair(-x, -y)) == s.end()) s.insert(make_pair(x, y));
        else s.erase(make_pair(-x, -y));
    }
    cout << (s.empty() ? "YES" : "NO") << endl;
    return 0;
}