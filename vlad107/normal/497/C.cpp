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

const int N = 500500;

struct State {
    int t, l, r, nom, k;
    State() {}
    State(int t, int l, int r, int nom, int k) : t(t), l(l), r(r), nom(nom), k(k) {}
    bool operator <(const State &q) const {
        if (r != q.r) return r < q.r;
        return t < q.t;
    }
};

int n, ans[N], m;
set<pair<int, int>> s;
vector<State> v;

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        v.push_back(State(0, l, r, i, 0));
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        v.push_back(State(1, l, r, i, k));
    }
    sort(v.begin(), v.end());
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < v.size(); i++) {
        if (v[i].t == 0) {
            s.insert(make_pair(v[i].l, v[i].nom));
        } else {
            for (int j = 0; j < v[i].k; j++) {
                auto it = s.lower_bound(make_pair(v[i].l, -1));
                if (it == s.end()) break;
                ans[it -> second] = v[i].nom;
                s.erase(it);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; i++) printf("%d ", ans[i] + 1);
}