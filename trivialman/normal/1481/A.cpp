#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, x, y;
string s;

int main() {
    cin >> T;

    rep(cas, 1, T) {
        cin >> x >> y >> s;
        int maxx = 0, maxy = 0, minx = 0, miny = 0;
        for (auto ch : s) {
            if (ch == 'L')
                minx--;
            if (ch == 'R')
                maxx++;
            if (ch == 'U')
                maxy++;
            if (ch == 'D')
                miny--;
        }
        if (minx <= x && x <= maxx && miny <= y && y <= maxy)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}