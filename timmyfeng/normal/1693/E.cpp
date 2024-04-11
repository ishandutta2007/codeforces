#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int fenwick[N], n;

void update(int a, int k) {
    if (a > n) return;
    fenwick[a] += k;
    update(a + (a & -a), k);
}

int query(int a) {
    return a ? fenwick[a] + query(a - (a & -a)) : 0;
}

int query(int a, int b) {
    return query(b) - query(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<pair<int, int>> points;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        points.push_back({a, i});
    }
    sort(points.rbegin(), points.rend());

    int left = 0, right = n - 1;
    long long answer = 0;

    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && points[j].first == points[i].first) ++j;
        int first = points[j - 1].second, last = points[i].second;

        if (first < left) answer += query(first + 1, left);
        if (last > right) answer += query(right + 1, last);
        if (!(last < left || first > right)) answer += query(max(first, left), min(last, right) + 1);

        int left_new = min(first, right + 1);
        int right_new = max(last, left - 1);

        left = left_new, right = right_new;

        for (int k = i; k < j; ++k) {
            update(points[k].second + 1, 1);
        }
    }

    if (points[n - 1].first) {
        cout << answer + n << "\n";
    } else {
        cout << answer + n - (right - left + 1) << "\n";
    }
}