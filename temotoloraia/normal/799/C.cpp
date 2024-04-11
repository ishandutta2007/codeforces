#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1011111111;

int n, x[2], mx[2];
int a[max_n], b[max_n], tp[max_n];

int solve(vector<pair<int, int> > v, int x) {
    if (v.size() < 2) {
        return 0;
    }
    sort(v.begin(), v.end());
    vector<int> mx[max_n];
    mx[0].push_back(v[0].second);
    for (int i = 1; i < v.size(); ++i) {
        mx[i] = mx[i - 1];
        mx[i].push_back(v[i].second);
        if (mx[i].size() > 2) {
            sort(mx[i].begin(), mx[i].end());
            reverse(mx[i].begin(), mx[i].end());
            mx[i].pop_back();
        }
    }
    int pos = 0, last = v.size() - 1, res = 0;
    while (pos < v.size()) {
        while (last >= 0 && v[pos].first + v[last].first > x) {
            --last;
        }
        if (pos == last) {
            --last;
        }
        if (last == -1) {
            break;
        }
        int pl = mx[last][0];
        if (pos <= last) {
            if (pl == v[pos].second) {
                pl = mx[last][1];
            }
        }
        res = max(res, v[pos].second + pl);
        ++pos;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    mx[0] = mx[1] = -inf;
    scanf("%d%d%d", &n, &x[0], &x[1]);
    vector<pair<int, int> > q[2];
    for (int i = 0; i < n; ++i) {
        char c;
        scanf("%d%d %c", &a[i], &b[i], &c);
        tp[i] = c - 'C';
        if (b[i] <= x[tp[i]]) {
            mx[tp[i]] = max(mx[tp[i]], a[i]);
        }
        q[tp[i]].push_back(make_pair(b[i], a[i]));
    }
    int ans = mx[0] + mx[1];
    ans = max(ans, solve(q[0], x[0]));
    ans = max(ans, solve(q[1], x[1]));
    printf("%d\n", ans);
    return 0;
}