#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
pair<int, int> p[maxn];
int a, b;

bool check(int i, int j) {
    if (p[i].first <= b && p[j].first <= b && p[i].second + p[j].second <= a) return true;
    if (p[i].second <= b && p[j].second <= b && p[i].first + p[j].first <= a) return true;
    if (p[i].first <= a && p[j].first <= a && p[i].second + p[j].second <= b) return true;
    if (p[i].second <= a && p[j].second <= a && p[i].first + p[j].first <= b) return true;
    if (p[i].first + p[j].second <= b && max(p[i].second, p[j].first) <= a) return true;
    if (p[i].second + p[j].first <= b && max(p[i].first, p[j].second) <= a) return true;
    if (p[i].second + p[j].first <= a && max(p[i].first, p[j].second) <= b) return true;
    if (p[i].first + p[j].second <= a && max(p[i].second, p[j].first) <= b) return true;
    return false;
}

int main() {
    int n; cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        if (p[i].first > p[i].second) swap(p[i].first, p[i].second);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (check(i, j)) ans = max(ans, p[i].first * p[i].second + p[j].first * p[j].second);
        }
    }
    cout << ans << endl;
    return 0;
}