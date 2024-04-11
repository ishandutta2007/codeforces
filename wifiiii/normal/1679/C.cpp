#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    set<int> sx, sy;
    vector<int> cx(n + 1), cy(n + 1);
    for(int i = 1; i <= n; ++i) {
        sx.insert(i);
        sy.insert(i);
    }
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y;
            cin >> x >> y;
            if(cx[x] == 0) sx.erase(x);
            if(cy[y] == 0) sy.erase(y);
            cx[x] += 1, cy[y] += 1;
        } else if(op == 2) {
            int x, y;
            cin >> x >> y;
            cx[x] -= 1, cy[y] -= 1;
            if(cx[x] == 0) sx.insert(x);
            if(cy[y] == 0) sy.insert(y);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            auto ix = sx.lower_bound(x1);
            auto iy = sy.lower_bound(y1);
            int ok = 2;
            if(ix != sx.end() && *ix <= x2) ok--;
            if(iy != sy.end() && *iy <= y2) ok--;
            cout << (ok ? "Yes" : "No") << '\n';
        }
    }
}