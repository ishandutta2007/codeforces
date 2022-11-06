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

int n;
map <int, point> all;
set <pair <point, int>> ans;

int main() {
    //read(FileName);
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        int a; cin >> a;
        ans.erase({all[a], a});
        --all[a].x;
        all[a].y = i;
        ans.insert({all[a], a});
    }
    cout << (*ans.begin()).y << endl;
}