#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

bool issqrt(long long t) {
    long long s = (long long)sqrt(t);
    while (s * s < t) {
        s++;
    }
    while (s * s > t) {
        s--;
    }
    return s * s == t;
}

vector<pair<long long, int>> factor(long long n) {
    vector<pair<long long, int>> res;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            pair<long long, int> p;
            p.first = i;
            while (n % i == 0) {
                n /= i;
                p.second++;
            }
            res.emplace_back(p);
        }
    }
    if (n != 1) {
        res.emplace_back(n, 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m = 1000001;
    vector<int> q(m);
    iota(q.begin(), q.end(), 0);
    for (int i = 1; i * i < m; i++) {
        for (int j = i * i; j < m; j += i * i) {
            q[j] = min(q[j], j / i / i);
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        sort(a.begin(), a.end());
        map<int, int> mp;
        map<int, int> tmp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tmp[a[i]]++;
            a[i] = q[a[i]];
            mp[a[i]]++;
        }
        vector<int> ans(4);
        for (auto e : tmp) {
            ans[1] = max(ans[1], e.second);
        }
        for (auto e : mp) {
            ans[2] = max(ans[2], e.second);
        }
        map<int, int> nmp;
        for (auto e : mp) {
            if (e.second % 2 == 1) {
                nmp[e.first] += e.second;
            } else {
                nmp[1] += e.second;
            }
        }
        swap(mp, nmp);
        for (auto e : mp) {
            ans[3] = max(ans[3], e.second);
        }
        int qq;
        cin >> qq;
        while (qq--) {
            long long w;
            cin >> w;
            if (w == 0) {
                cout << ans[2] << '\n';
            } else if (w == 1) {
                cout << ans[3] << '\n';
            } else {
                cout << ans[3] << '\n';
            }
        }
    }
    return 0;
}