#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int best = N;
int a[N];
set <int> used;
mt19937 rnd(239);

vector <int> fact(int n) {
    int i = 2;
    vector <int> res;
    while (i * i <= n) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) n /= i;
        }
        i++;
    }
    if (n != 1) res.push_back(n);
    return res;
}

void eval(int n, int x) {
    if (used.find(x) != used.end()) return;
    used.insert(x);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur > best) return;
        if (a[i] < x) {
            cur += x - a[i];
            continue;
        }
        int v = a[i] % x;
        cur += min(v, x - v);
    }
    best = min(best, cur);
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    best = n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 20; i++) {
        int pos = rnd() % n;
        for (int x = -2; x <= 2; x++) {
            int cur = a[pos] + x;
            if (cur <= 1) continue;
            auto v = fact(cur);
            for (int elem : v) eval(n, elem);
        }
    }
    cout << best << endl;
}