#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 1e9 + 7;

int bpow(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n % 2 == 0) {
        int mem = bpow(a, n / 2);
        if (mem == M) return M;
        if (mem * mem >= M) return M;
        return mem * mem;
    }
    int mem = bpow(a, n - 1);
    if (mem == M) return M;
    if (a * mem >= M) return M;
    return a * mem;
}

int bpoww(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a % M;
    if (n % 2 == 0) {
        int mem = bpoww(a, n / 2);
        return (mem * mem) % M;
    }
    int mem = bpoww(a, n - 1);
    return (a * mem) % M;
}

void solve() {
    int n, p;
    cin >> n >> p;
    map <int, int, greater <int>> cnt;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        cnt[k]++;
    }
    int realdiff = 0;
    pair <int, int> diff = {M, 0};
    while (!cnt.empty()) {
        auto x = *cnt.begin();
        cnt.erase(cnt.begin());
        //cout << diff.first << ' ' << x.first << endl;
        if (diff.second == 0) diff.first = x.first;
        else {
            int mul = bpow(p, diff.first - x.first);
            if (mul == M || diff.second == M) diff.second = M;
            else {
                diff.second *= mul;
                if (diff.second > M) diff.second = M;
            }
            diff.first = x.first;
        }
        //cout << diff.second << ' ' << realdiff << endl;
        if (x.second < diff.second) {
            diff.second -= x.second;
            realdiff = (realdiff - bpoww(p, diff.first) * x.second) % M;
            if (realdiff < 0) realdiff += M;
        } else {
            x.second -= diff.second;
            if (x.second % 2 == 0) {
                realdiff = 0;
                diff.second = 0;
            } else {
                diff.second = 1;
                //cout << p << ' ' << diff.first << endl;
                realdiff = bpoww(p, diff.first);
            }
        }

    }
    cout << realdiff << "\n";
    /*vector <pair <int, int>> digs;
    while (!cnt.empty()) {
        auto x = *cnt.begin();
        cnt.erase(cnt.begin());
        cnt[x.first + 1] += x.second / p;
        digs.push_back({x.first, x.second % p});
    }
    int diff = 0;
    reverse(digs.begin(), digs.end());
    bool flag = 0;
    for (auto elem : digs) {
        if (flag) {
            diff = (diff - bpow(p, elem.first) * elem.second) % M;
            if (diff < 0) diff += M;
        } else {
            if ()
        }
    }*/
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}