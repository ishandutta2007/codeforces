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

const int N = 1000000;

bool used[N], pr[N];
int n;
vector< pair<int, int> > ans;

void doit(int x) {
    vector<int> v;
    for (int i = x; i <= n; i += x) {
        if (!used[i]) {
            v.push_back(i);
        }
    }
    reverse(v.begin(), v.end());
    if (v.size() % 2 == 1) {
        v.pop_back();
        if (v.size() == 0) {
            return;
        }
        v[v.size() - 1] = x;
    }
    for (int i = 0; i < v.size(); i += 2) {
        ans.push_back(make_pair(v[i], v[i + 1]));
        used[v[i]] = true;
        used[v[i + 1]] = true;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        pr[i] = 1;
    }
    memset(used, 0, sizeof(used));
    for (int i = 2; i <= n; i++) {
        if (pr[i]) {
            for (int j = i; j <= n; j += i) {
                pr[j] = 0;
            }
        }
    }
    for (int i = 3; i <= n; i++) {
        doit(i);
    }
    doit(2);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}