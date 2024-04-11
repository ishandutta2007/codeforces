#include <bits/stdc++.h>

using namespace std;

vector<int> q, p;

int ask(int i) {
    cout << "?  " << i+1 << endl;
    int res; cin >> res; --res;
    return res;
}

void answer(const vector<int>& w) {
    cout << "!";
    for (int x : w) cout << ' ' << x+1;
    cout << endl;
}

void solve() {
    int n; cin >> n;

    vector<char> was(n);
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        if (was[i]) continue;

        int v0;
        vector<int> u;
        while (!was[v0 = ask(i)]) was[v0] = true, u.push_back(v0);

        int w = u.size();
        u.push_back(u.front());
        for (int i = 0; i < w; ++i) p[u[i]] = u[i+1];
    }

    answer(p);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}