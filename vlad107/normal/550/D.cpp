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
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

const int N = 1e6;

int n, k;
vector< pair<int, int> > e;
vector< vector<int> > vv;
int cnt[N];

void gen(int x) {
    vector<int> v;
    for (int i = 0; i < k - 1; i++) {
        e.push_back(make_pair(x, n));
        v.push_back(n);
        n++;
    }
    vv.resize(v.size());
    for (int i = 0; i < v.size(); i++) {
        int x = v[i];
        vv[i].clear();
        for (int j = 0; j < k - 1; j++) {
            e.push_back(make_pair(x, n));
            vv[i].push_back(n);
            n++;
        }
        if (i & 1) {
            for (int j0 = 0; j0 < vv[i - 1].size(); j0++) {
                for (int j1 = 0; j1 < vv[i].size(); j1++) {
                    int u0 = vv[i - 1][j0];
                    int u1 = vv[i][j1];
                    e.push_back(make_pair(u0, u1));
                }
            }
        }
    }
}

void check() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < e.size(); i++) {
        cnt[e[i].first]++;
        cnt[e[i].second]++;
    }
    for (int i = 0; i < n; i++) assert(cnt[i] == k);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &k);
    if (k % 2 == 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    n = 2;
    gen(0);
    gen(1);
    e.push_back(make_pair(0, 1));
    check();
    cout << n << " " << e.size() << endl;
    for (int i = 0; i < e.size(); i++) printf("%d %d\n", e[i].first + 1, e[i].second + 1);
}