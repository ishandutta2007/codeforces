#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long lint;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

struct vertex {
    int id, s;
    vertex(int i, int s)
      : id(i), s(s) { }
};
bool operator < (const vertex& u, const vertex& v)
{
    return u.s > v.s;
}

int main()
{
    int n;
    priority_queue<vertex> Q[2];

    scanf("%d", &n);

    bool all_zero = true;

    for (int i = 0; i < n; ++i) {
        int c, s;
        scanf("%d%d", &c, &s);
        Q[c].push(vertex(i, s));
        all_zero &= s == 0;
    }

    if (all_zero) {
        vector<int> v[2];
        for (int i = 0; i < 2; ++i) {
            while (!Q[i].empty()) {
                v[i].push_back(Q[i].top().id);
                Q[i].pop();
            }
        }

        for (int i = 0; i < (int)v[0].size(); ++i) {
            printf("%d %d 0\n", v[1][0] + 1, v[0][i] + 1);
        }
        for (int i = 1; i < (int)v[1].size(); ++i) {
            printf("%d %d 0\n", v[0][0] + 1, v[1][i] + 1);
        }

        return 0;
    }

    for (int i = 0; i < n-1; ++i) {
        vertex u = Q[0].top(); Q[0].pop();
        vertex v = Q[1].top(); Q[1].pop();

        int sub = min(u.s, v.s);
        u.s -= sub;
        v.s -= sub;

        printf("%d %d %d\n", u.id + 1, v.id + 1, sub);

        if (u.s == 0) {
            Q[1].push(v);
        } else {
            Q[0].push(u);
        }
    }

    return 0;
}