#include <bits/stdc++.h>
using namespace std;

int maxi;

void update(int x, int a) {
    while (maxi < x) {
        cout << a << " ";
        ++maxi;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 2>> points;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        points.push_back({a, i});
    }

    sort(points.rbegin(), points.rend());
    map<int, int> segments;

    for (auto [a, i] : points) {
        auto it = segments.lower_bound(i);
        if (it != segments.end() && it->first == i + 1) {
            segments[i] = it->second;
            update(it->second - i + 1, a);
            segments.erase(it);
        } else {
            segments[i] = i;
            update(1, a);
        }

        it = segments.find(i);
        if (it != segments.begin() && (--it)->second == i - 1) {
            it->second = segments[i];
            update(segments[i] - it->first + 1, a);
            segments.erase(i);
        }
    }
}