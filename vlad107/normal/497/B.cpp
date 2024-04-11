#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

#define next ___next

const int N = 500500;

vector<int> g[2];
vector<pair<int, int>> res;
int ta[N], next[N], n, nom[N];

void check(int t) {
    int i = 0;
    int c0 = 0, c1 = 0;
    int last = -1;
    while (i < n) {
        int j = next[i];
        int nx = nom[i] + t - 1 < g[ta[i]].size() ? g[ta[i]][nom[i] + t - 1] : n;
        int ny;
        if (j == n) ny = n; else
        ny = nom[j] + t - 1 < g[1 - ta[i]].size() ? g[1 - ta[i]][nom[j] + t - 1] : n;   
        if ((nx == n) && (ny == n)) return;
        if (ta[i]) swap(nx, ny);
        if (nx < ny) {
            c0++;
            i = nx + 1;
            last = 0;
        } else {
            c1++;
            i = ny + 1;
            last = 1;
        }
    }
    if ((last == 0) && (c1 >= c0)) return;
    if ((last == 1) && (c0 >= c1)) return;
    if ((i == n) && (c0 != c1)) {
        res.push_back(make_pair(max(c0, c1), t));
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ta[i]);
        --ta[i];
        nom[i] = g[ta[i]].size();
        g[ta[i]].push_back(i);
    }
    next[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (ta[i] == ta[i + 1]) next[i] = next[i + 1]; else
        next[i] = i + 1;
    }
    for (int t = 1; t <= n; t++) {
        check(t);
    }
    sort(res.begin(), res.end());
    printf("%d\n", (int)res.size());
    for (int i = 0; i < res.size(); i++) printf("%d %d\n", res[i].first, res[i].second);
}