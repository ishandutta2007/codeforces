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

const int INF = (int)1e9 + 1;
const long long INFINF = (long long)1e18 + 1;
const int N = 1111111;

long long sa[2][N], f[N];
pair<int, int> a[N];
int n;
vector<pair<int, int> > v;

long long fmax(int x, int t) {
    long long res = -INFINF;
    while (t) {
        res = max(res, sa[x][t]);
        t &= t - 1;
    }
    return res;
}

void upd(int x, int t, long long val) {
    while (t <= n) {
        sa[x][t] = max(sa[x][t], val);
        t = (t | (t - 1)) + 1;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        v.push_back(make_pair(a[i].first, i));
    }
    sort(v.begin(), v.end());
    int last = -INF;
    int cnt = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i].first != last) {
            last = v[i].first;
            cnt++;
        }
        a[v[i].second].second = cnt;
    }
    for (int i = 1; i <= n; i++) {
        sa[0][i] = sa[1][i] = -INFINF;
    }
    upd(0, a[0].second, -a[0].first);
    upd(1, n + 1 - a[0].second, a[0].first);
    for (int i = 0; i < n; i++) {
        f[i] = 0;
        if (i > 0) f[i] = max(f[i], f[i - 1]);
        f[i] = max(f[i], fmax(0, a[i].second) + a[i].first);
        f[i] = max(f[i], fmax(1, n - a[i].second + 1) - a[i].first);
        if (i + 1 < n) {
            upd(0, a[i + 1].second, f[i] - a[i + 1].first);
            upd(1, n + 1 - a[i + 1].second, f[i] + a[i + 1].first);
        }
    }
    cout << f[n - 1] << endl;
}