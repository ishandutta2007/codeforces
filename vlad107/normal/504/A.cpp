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

const int N = 1 << 17;

int n, deg[N], s[N];
set<pair<int, int>> e;

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &deg[i], &s[i]);
        e.insert(make_pair(deg[i], i));
    }
    vector<pair<int, int>> ans;
    while (!e.empty()) {
        pair<int, int> cur = *e.begin();
        e.erase(e.begin());
        if (cur.first == 0) continue;
        if (cur.first != 1) break;
        ans.push_back(make_pair(cur.second, s[cur.second]));
        int x = s[cur.second];
        s[x] ^= cur.second;
        e.erase(make_pair(deg[x], x));
        deg[x]--;
        e.insert(make_pair(deg[x], x));
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
}