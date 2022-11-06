#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;

int main() {
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        int lb = 0, ub = 0;
        for (int j = i; j < s.size(); ++j) {
            if (s[j] == '(') ++lb, ++ub;
            else if (s[j] == ')') --lb, --ub;
            else --lb, ++ub;
            if (ub < 0) break;
            if (lb < 0) lb += 2;
            if (lb == 0) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}