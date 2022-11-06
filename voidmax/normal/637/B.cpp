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
map <string, int> all;

bool operator < (pair <int, string> a, pair <int, string> b) {
    return a.x < b.x;
}

set <pair <int, string>> ans;

int main() {
    //read(FileName);
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        string a; cin >> a;
        ans.erase({all[a], a});
        all[a] = -i;
        ans.insert({all[a], a});
    }
    for(auto i: ans)
        cout << i.y << endl;
}