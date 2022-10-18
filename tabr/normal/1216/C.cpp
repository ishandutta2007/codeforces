#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
 
vector<int> x(7), y(7);
bool ok = false;
 
void solve(int s) {
    if (x[s] <= x[1] && x[2] <= x[s + 1] && y[s] <= y[1] && y[2] <= y[s + 1])
        ok = true;
 
    if (x[s] <= x[1] && x[2] <= x[s + 1]) {
        if (y[s] <= y[1] && y[2] <= y[s + 1]) {
            ok = true;
        } else if (y[s] <= y[1]) {
            y[1] = max(y[1],y[s + 1]);
        } else if (y[2] <= y[s + 1]) {
            y[2] = min(y[2],y[s]);
        }
    }
    if (y[s] <= y[1] && y[2] <= y[s + 1]) {
        if (x[s] <= x[1] && x[2] <= x[s + 1]) {
            ok = true;
        } else if (x[s] <= x[1]) {
            x[1] = max(x[1],x[s + 1]);
        } else if (x[2] <= x[s + 1]) {
            x[2] = min(x[2],x[s]);
        }
    }
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    rep(i, 1, 7) cin >> x[i] >> y[i];
 
    solve(3);
    solve(5);
    if (ok)
        puts("NO");
    else
        puts("YES");
 
    return 0;
}