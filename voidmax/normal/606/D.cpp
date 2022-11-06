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
#include <queue>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

int n, m;
int L = 2, R = 0, cnt = 1;

vector <pair<point, int>> edge;
vector <point> ans(1000001);
map <point, int> num;

void NextEdge() {
    if (R == 0) {
        ++L; R = L - 2;
    } else {
        --R;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    For(i, 0, m) {
        int X, Y;
        cin >> X >> Y;
        edge.push_back({{X, -Y}, i});
    }
    sort(edge.begin(), edge.end());
    For(i, 0, m) {
        if (edge[i].x.y == -1) {
            ans[edge[i].y] = {cnt - 1, cnt};
            ++cnt;
        } else {
            if (L >= cnt) {
                cout << -1 << endl;
                return 0;
            }
            ans[edge[i].y] = {L, R};
            NextEdge();
        }
    }
    For(i, 0, m) {
        cout << ans[i].y + 1 << ' ' << ans[i].x + 1 << endl;
    }
}