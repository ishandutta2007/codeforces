#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int>> ord;
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        ord.push_back({d, 2 * i - 1});
    }
    sort(ord.begin(), ord.end(), greater <pair <int, int>> ());
    deque <int> cur;
    vector <pair <int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        ans.push_back({ord[i].second, ord[i + 1].second});
    }
    for (auto elem : ord) cur.push_back(elem.second);
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            if (cur[1] == ord[i].second) cur.pop_front();
            else cur.push_front(ord[i].second);
        }
        ans.push_back({cur[ord[i].first - 1], ord[i].second + 1});
        while ((int) cur.size() != ord[i].first) cur.pop_back();
        cur.push_back(ord[i].second + 1);
    }
    for (auto elem : ans) {
        cout << elem.first << ' ' << elem.second << "\n";
    }
    return 0;
}