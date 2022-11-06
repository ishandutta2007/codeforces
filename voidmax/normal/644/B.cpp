//#include "grader.h"
#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

base n, b;
base rep[200002];
base d[200002];
set <pair <base, base>> ans;
queue <base> que;

base TimeNow = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> b;
    For(i, 1, n + 1) {
        base t;
        cin >> t >> d[i];
        rep[i] = -1;
        ans.insert({t, i});
    }
    while (ans.size()) {
        auto u = *ans.begin();
        ans.erase(u);
        TimeNow = u.x;
        if (u.y < 0) {
            rep[-u.y] = u.x;
            que.pop();
            if (que.size()) {
                int v = que.front();
                ans.insert({TimeNow + d[v], -v});
            }
        } else {
            if (que.size() == b + 1) continue;
            que.push(u.y);
            if (que.size() == 1) {
                ans.insert({TimeNow + d[u.y], -u.y});
            }
        }
    }
    For(i, 1, n + 1) cout << rep[i] << ' ';
}