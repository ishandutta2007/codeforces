/*
 - - - - - - - -
 
 ***********
 ***********
 ***
 ***
 ***********
 ***********
 ***
 ***
 ***********
 ***********
 
 - - - - - - - -
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

int X, Y;
point s;
map <point, int> arr;
int ans[2000001];
string Way;

void add(point a, int i) {
    if (arr.count(a) == 0) {
        arr[a] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> X >> Y >> s.x >> s.y;
    cin >> Way;
    --s.x; --s.y;
    For(i, 0, Way.size()) {
        add(s, i);
        if (Way[i] == 'U') s.x--;
        if (Way[i] == 'D') s.x++;
        if (Way[i] == 'L') s.y--;
        if (Way[i] == 'R') s.y++;
        s.x = max(s.x, 0);
        s.x = min(s.x, X - 1);
        s.y = max(s.y, 0);
        s.y = min(s.y, Y - 1);
    }
    add(s, Way.size());
    For(i, 0, X) {
        For(j, 0, Y) {
            if (arr.count({i, j}) == 0) {
                ++ans[(int)Way.size()];
            } else {
                ++ans[arr[{i, j}]];
            }
        }
    }
    For(i, 0, Way.size() + 1) {
        cout << ans[i] << ' ';
    }
}