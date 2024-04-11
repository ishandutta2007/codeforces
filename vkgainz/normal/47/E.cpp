#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
using namespace std;

struct query {
    double x;
    int y;
};

bool cmp(query &x, query &y) {
    return x.x < y.x;
}

double getX(int V, double alpha) {
    return V * V * 1.0 * sin(2 * alpha) / 9.8;
}

int main() {
    int n, V; cin >> n >> V;
    vector<query> queries(n);
    for (int i = 0; i < n; i++) {
        cin >> queries[i].x;
        queries[i].y = i;
    }
    sort(queries.begin(), queries.end(), cmp);
    int m; cin >> m;
    vector<pair<double, double>> wall(m);
    for (int i = 0; i < m; i++) {
        double x, y; cin >> x >> y;
        wall[i] = {x, y};
    }
    sort(wall.begin(), wall.end());
    vector<pair<double, double>> ans(n);
    for (int i = 0; i < n; i++) {
        double x = getX(V, queries[i].x);
        ans[queries[i].y] = {x, 0.0};
    }
    int hit = 0;
    for (int i = 0; i < n; i++) {
        while (hit < m) {
            double time = wall[hit].first / (V * 1.0 * cos(queries[i].x));
            double ypos = V * 1.0 * sin(queries[i].x) * time
                - 4.9 * time * time;
            if (ypos <= wall[hit].second) {
                if (ypos >= 0) {
                    ans[queries[i].y] = {wall[hit].first, ypos};
                }
                break;
            } else {
                ++hit;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}