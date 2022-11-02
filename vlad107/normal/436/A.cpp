#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

#define N 2222

struct Point {
    int t, h, m;
};

int n, x;
Point a[N];
int f[N][N][2];
vector<pair<int, int> > v[2];
bool used[2][N];

bool cmp(Point x, Point y) {
    if (x.h != y.h) {
        return x.h < y.h;
    }
    return x.m > y.m;
}

int solve(int st) {
    int u = x;
    int i = 0;
    int j = 0;
    int ans = 0;
    memset(used, 0, sizeof(used));
    while (1) {
        int mt = -1;
        int nt;
        for (int i = 0; i < v[0].size(); i++) {
            if ((!used[0][i]) && (u >= v[0][i].first) && (v[0][i].second > mt)) {
                mt = v[0][i].second;
                nt = i;
            }
        }
        if (mt < 0) {
            break;
        }
        ans++;
        used[0][nt] = true;
        u += mt;
        mt = -1;
        for (int i = 0; i < v[1].size(); i++) {
            if ((!used[1][i]) && (u >= v[1][i].first) && (v[1][i].second > mt)) {
                mt = v[1][i].second;
                nt = i;
            }
        }
        if (mt < 0) {
            break;
        }
        used[1][nt] = true;
        ans++;
        u += mt;
    }
    vector<pair<int, int> > tmp = v[0];
    v[0] = v[1];
    v[1] = tmp;
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i].t, &a[i].h, &a[i].m);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        v[a[i].t].push_back(make_pair(a[i].h, a[i].m));
    }
    printf("%d\n", max(solve(0), solve(1)));
}