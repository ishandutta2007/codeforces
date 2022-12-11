#include <bits/stdc++.h>
//#define int long long

using namespace std;

vector <pair <int, int>> f(int n) {
    int i = 2;
    vector <pair <int, int>> res;
    while (i * i <= n) {
        if (n % i == 0) {
            res.push_back({i, 0});
            while (n % i == 0) {
                n /= i;
                res.back().second++;
            }
        }
        i++;
    }
    if (n != 1) res.push_back({n, 1});
    return res;
}

int get(long long p, int div) {
    int res = 0;
    while (p % div == 0) {
        p /= div;
        res++;
    }
    return res;
}

void solve() {
    long long p, q;
    cin >> p >> q;
    auto x = f(q);
    long long mini = p;
    for (pair <int, int> elem : x) {
        int d = elem.first, cnt = elem.second;
        int cnt2 = get(p, d);
        long long cur = 1;
        while (cnt2 >= cnt) {
            cnt2--;
            cur *= d;
        }
        mini = min(mini, cur);
    }
    cout << p / mini << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}