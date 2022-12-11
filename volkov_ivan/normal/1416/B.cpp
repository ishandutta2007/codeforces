#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 7;
int a[N];

struct query{
    int i, j, x;
    query() {}
    query(int i, int j, int x): i(i), j(j), x(x) {}
};

void solve() {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if (s % n != 0) {
        cout << "-1\n";
        return;
    }
    vector <query> res;
    for (int i = 2; i <= n; i++) {
        int rest = a[i] % i;
        if (rest != 0) {
            int need = i - rest;
            res.push_back(query(1, i, need));
            a[i] += need;
        }
        res.push_back(query(i, 1, a[i] / i));
    }
    for (int i = 2; i <= n; i++) {
        res.push_back(query(1, i, s / n));
    }
    cout << res.size() << "\n";
    for (auto elem : res) {
        cout << elem.i << ' ' << elem.j << ' ' << elem.x << "\n";
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}