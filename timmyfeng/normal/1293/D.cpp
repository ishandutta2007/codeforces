#include <bits/stdc++.h>
using namespace std;

long long ax, ay, bx, by, t, xo, yo, sx, sy;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> xo >> yo >> ax >> ay >> bx >> by >> sx >> sy >> t;
    vector<long long> x(1, xo), y(1, yo);
    while (x.back() * ax + bx < (1LL << 55) && y.back() * ax + bx < (1LL << 55)) {
        x.push_back(x.back() * ax + bx);
        y.push_back(y.back() * ay + by);
    }

    int sol = 0;
    for (int i = 0; i < x.size(); i++)
        for (int j = i; j < x.size(); j++) {
            long long to_end = min(abs(sx - x[i]) + abs(sy - y[i]), abs(sx - x[j]) + abs(sy - y[j]));
            long long dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            if (dist + to_end <= t) sol = max(sol, j - i + 1);
        }
    cout << sol << "\n";
}