#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

int n, m, s, d;

set <int> arr;
vector <pair <string, int>> ans;

bool OK(int L) {
    if (arr.lower_bound(L) == arr.end()) return true;
    int R = *arr.lower_bound(L);
    return R - L - 1 >= s;
}

int main() {
    //read(FileName);
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> d;
    For(i, 0, n) {
        int a; cin >> a;
        arr.insert(a);
    }
    int coor = 0;
    while (coor != m) {
        if (arr.lower_bound(coor) == arr.end()) {
            ans.pb({"RUN", m - coor});
            coor = m;
            continue;
        }
        if (!OK(coor)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        int R = *arr.lower_bound(coor);
        ans.pb({"RUN", R - coor - 1});
        coor = R - 1;
        auto It = arr.lower_bound(coor);
        bool OK1 = false;
        while (It != arr.end() && !((*It) + 1 - coor > d)) {
            if (OK((*It) + 1)) {
                ans.pb({"JUMP", (*It) + 1 - coor});
                coor = (*It) + 1;
                OK1 = true;
                break;
            }
            ++It;
        }
        if (!OK1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for(auto i: ans) cout << i.x << ' ' << i.y << endl;
}