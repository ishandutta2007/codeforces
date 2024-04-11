#include <stdio.h>
#include <iostream>
#include <set>
#include <map>

using namespace std;

const int BASE = 1e9 + 9;
const int N = 1e5 + 20;

int x[N], y[N], cnt[N];
set<pair<int, int>> s;
set<int> e;
map<pair<int, int>, int> rev;
int res, n;

void add(int x, int y) {
    for (int i = -1; i <= 1; i++) {
        int cx = x + i;
        int cy = y + 1;
        if (rev.count(make_pair(cx, cy)) == 0) continue;
        int nom = rev[make_pair(cx, cy)];
        if (cnt[nom] == 1) return;
    }
    s.erase(make_pair(x, y));
    e.insert(rev[make_pair(x, y)]);
}

void upd(int x, int y) {
    if (rev.count(make_pair(x, y)) == 0) return;
    int nom = rev[make_pair(x, y)];
    if (e.find(nom) != e.end()) {
        e.erase(nom);
        s.insert(make_pair(x, y));
        add(x, y);
    }
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        rev[make_pair(x[i], y[i])] = i;
        s.insert(make_pair(x[i], y[i]));
    }
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            if (s.find(make_pair(x[i] + j, y[i] - 1)) != s.end()) {
                cnt[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        add(x[i], y[i]);
    }
    for (int it = 0; it < n; it++) {
        int o;
        if (it & 1) {
            auto uu = e.begin();
            o = *uu;
        } else {
            auto uu = e.end();
            --uu;
            o = *uu;
        }
        e.erase(e.find(o));
        res = (res * 1LL * n + o) % BASE;
        cnt[o] = 0;
        for (int j = -1; j <= 1; j++) {
            auto it = s.find(make_pair(x[o] + j, y[o] - 1));
            if (it == s.end()) continue;
            add(x[o] + j, y[o] - 1);
        }
        for (int j = -1; j <= 1; j++) {
            if (rev.count(make_pair(x[o] + j, y[o] + 1)) != 0) {
                cnt[rev[make_pair(x[o] + j, y[o] + 1)]]--;
            }
        }
        upd(x[o] - 1, y[o]);
        upd(x[o] + 1, y[o]);
        upd(x[o] - 2, y[o]);
        upd(x[o] + 2, y[o]);
    }
    printf("%d\n", res);
}