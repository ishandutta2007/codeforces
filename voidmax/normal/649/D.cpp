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

int n;
bool used[200001];
int LR[200001][2];
base cnt = 0;
vector <pair <int, int>> ans;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        int a; cin >> a;
        if (a == 0) continue;
        if (!used[a - 1]) {
            LR[a - 1][0] = i;
            used[a - 1] = true;
        }
        LR[a - 1][1] = i;
    }
    For(i, 0, n) {
        if (used[i]) {
            ans.pb({LR[i][0], LR[i][1]});
        }
    }
    sort(ans.begin(), ans.end());
    int L = 0;
    For(i, 0, ans.size()) {
        int M = ans[i].x - L;
        int Ln = ans[i].x, Rn = ans[i].y;
        ans[i].x -= M;
        ans[i].y -= M;
        L = ans[i].y + 1;
        //cout << ans[i].x << ' ' << ans[i].y << ' ' << Ln << ' ' << Rn << endl;
        M = Rn - Ln  - max(0, -(max(Ln, ans[i].x) - min(Rn, ans[i].y)) + 1) + 1;
        //cout << M << endl;
        cnt += M;
    }
    cout << cnt << endl;
}