#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, sq = 32000, maxv = 1e9;
int a[maxn], n, k;
vector<int> cur;
vector<pair<int, int>> kfac;

vector<pair<int, int>> fact(int);
bool check();
void add(int);
void sub(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (k == 1) return cout << (long long)n * (long long)(n - 1) / 2 + (long long)n << endl, 0;
    kfac = fact(k); cur.resize((int)kfac.size());
    long long ans = 0; add(a[0]);
    for (int l = 0, r = 0; l < n; ++l) {
        while (r < n && !check()) ++r, add(a[r]);
        ans += n - r; // cout << "ansr = " << r << endl;
        sub(a[l]);
    }
    cout << ans << endl;
    return 0;
}

vector<pair<int, int>> fact(int k) {
    vector<pair<int, int>> ret;
    int p = 2;
    while (k > 1) {
        int cnt = 0;
        while (k % p == 0) k /= p, ++cnt;
        if (cnt) ret.push_back(make_pair(p, cnt));
        ++p;
    }
    return ret;
}

bool check() {
    for (int i = 0; i < cur.size(); ++i) {
        if (cur[i] < kfac[i].second) return false;
    }
    return true;
}

void add(int t) {
    // cout << "add(" << t << ")" << endl;
    if (!t) return;
    for (int i = 0; i < kfac.size(); ++i) {
        int tmp = t, cnt = 0;
        while (tmp % kfac[i].first == 0) tmp /= kfac[i].first, ++cnt;
        cur[i] += cnt;
    }
}

void sub(int t) {
    // cout << "sub(" << t << ")" << endl;
    if (!t) return;
    for (int i = 0; i < kfac.size(); ++i) {
        int tmp = t, cnt = 0;
        while (tmp % kfac[i].first == 0) tmp /= kfac[i].first, ++cnt;
        cur[i] -= cnt;
    }
}