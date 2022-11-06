#include <bits/stdc++.h>
using namespace std;

const int maxn = 60000 + 5;
const double eps = 1e-7;
int n, x[maxn], v[maxn];

double bs(double, double);
bool check(double);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int Max = INT_MIN, Min = INT_MAX;
    for (int i = 0; i < n; ++i) cin >> x[i], Max = max(Max, x[i]), Min = min(Min, x[i]);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << fixed << setprecision(10) << bs(0, Max - Min) << '\n';
    return 0;
}

double bs(double L, double R) {
    if (fabs(R - L) < eps) return L;
    double M = (L + R) / 2;
    if (check(M)) return bs(L, M);
    return bs(M, R);
}

bool check(double t) {
    vector<pair<double, int>> vec;
    for (int i = 0; i < n; ++i) {
        vec.push_back(make_pair((double)x[i] - (double)v[i] * t, 1));
        vec.push_back(make_pair((double)x[i] + (double)v[i] * t, -1));
    }
    sort(vec.begin(), vec.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });
    int cur = 0, Max = 0;
    for (auto i : vec) {
        cur += i.second;
        Max = max(Max, cur);
    }
    return Max == n;
}