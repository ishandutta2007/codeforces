#include <bits/stdc++.h>
using namespace std;

const int maxn = 600 + 10;
int l[maxn], r[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    stack<string> stk;
    for (int i = n - 1; i >= 0; --i) {
        string now = "(";
        while (stk.size() && now.size() < l[i]) now += stk.top(), stk.pop();
        now += ')';
        if (now.size() < l[i] + 1 || now.size() > r[i] + 1) return cout << "IMPOSSIBLE" << endl, 0;
        stk.push(now);
    }
    while (stk.size()) cout << stk.top(), stk.pop(); cout << endl;
    return 0;
}