#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 1;

int main() {
    int n; cin >> n;
    string s;
    int ub = inf, lb = -inf;
    while (n--) {
        cin >> s;
        int x; cin >> x;
        char c; cin >> c;
        if (s == ">=") {
            if (c == 'Y') lb = max(lb, x);
            else ub = min(ub, x - 1);
        }
        if (s == "<=") {
            if (c == 'Y') ub = min(ub, x);
            else lb = max(lb, x + 1);
        }
        if (s == "<") {
            if (c == 'Y') ub = min(ub, x - 1);
            else lb = max(lb, x);
        }
        if (s == ">") {
            if (c == 'Y') lb = max(lb, x + 1);
            else ub = min(ub, x);
        }
    }
    if (lb > ub) cout << "Impossible" << endl;
    else cout << lb << endl;
    return 0;
}