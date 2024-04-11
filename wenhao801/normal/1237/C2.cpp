#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 50050;
struct pt { int x, y, z, id; } a[MAXN];

pair <bool, pt> solve_z(vector <pt> &v) {
    sort(v.begin(), v.end(), [](pt u, pt v) { return u.z < v.z; });
    for (int i = 0; i + 1 < v.size(); i += 2) printf("%d %d\n", v[i].id, v[i + 1].id);
    if (v.size() & 1) return {1, v.back()};
    else return {0, pt{0, 0, 0, 0}};
}
pair <bool, pt> solve_y(const vector <pt> &v) {
    bool hav = 0; pt o;
    map <int, vector <pt>> mp;
    for (auto i: v) mp[i.y].push_back(i);
    for (auto i: mp) {
        auto res = solve_z(i.second);
        if (res.first) {
            if (!hav) hav = 1, o = res.second;
            else printf("%d %d\n", o.id, res.second.id), hav = 0;
        }
    }
    return {hav, o};
}
void solve_x(const vector <pt> &v) {
    bool hav = 0; pt o;
    map <int, vector <pt>> mp;
    for (auto i: v) mp[i.x].push_back(i);
    for (auto i: mp) {
        auto res = solve_y(i.second);
        if (res.first) {
            if (!hav) hav = 1, o = res.second;
            else printf("%d %d\n", o.id, res.second.id), hav = 0;
        }
    }
}

int main() {
    int n = read(), i;
    vector <pt> v;
    for (i = 1; i <= n; i++) a[i].x = read(), a[i].y = read(), a[i].z = read(), a[i].id = i, v.push_back(a[i]);
    solve_x(v);
    return 0;
}