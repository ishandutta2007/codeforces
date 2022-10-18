#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int dfs(vector<int> x, int b) {
    if (x.empty()) {
        return 1 << (b + 1);
    }
    int res = 0;
    vector<int> s, t;
    for (int e : x) {
        if (e >= (1 << b))
            s.emplace_back(e - (1 << b));
        else
            t.emplace_back(e);
    }
    if ((s.empty() || t.empty()) == false) res = 1 << b;
    if (b != 0) {
        res += min(dfs(s, b - 1), dfs(t, b - 1));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, mx = (1 << 30) - 1;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    cout << dfs(a, 29) << endl;
    return 0;
}