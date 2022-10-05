//
// Created by Danny Mittal on 9/30/20.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> robbers[2000];
pair<int, int> searchlightsOrig[2000];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int j = 0; j < n; j++) {
        cin >> robbers[j].first >> robbers[j].second;
    }
    for (int j = 0; j < m; j++) {
        cin >> searchlightsOrig[j].first >> searchlightsOrig[j].second;
    }
    sort(searchlightsOrig, searchlightsOrig + m);
    vector<pair<int, int>> searchlights;
    int maxY = -1;
    for (int j = m - 1; j >= 0; j--) {
        if (searchlightsOrig[j].second > maxY) {
            maxY = searchlightsOrig[j].second;
            searchlights.push_back(searchlightsOrig[j]);
        }
    }
    sort(searchlights.begin(), searchlights.end());
    vector<pair<int, int>> updates;
    for (int r = 0; r < n; r++) {
        for (auto l : searchlights) {
            updates.emplace_back(l.second - robbers[r].second, l.first - robbers[r].first);
        }
    }
    sort(updates.begin(), updates.end());
    int answer = 1000000000;
    int dx = 0;
    for (int j = updates.size() - 1; j >= 0; j--) {
        auto u = updates[j];
        //cout << u.second << " " << u.first << endl;
        answer = min(answer, dx + max(u.first + 1, 0));
        dx = max(dx, u.second + 1);
    }
    answer = min(answer, dx);
    cout << answer << endl;
}