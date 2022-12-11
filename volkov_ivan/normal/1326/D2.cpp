#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")


 
using namespace std;

 
vector <int> z;
const int N = 1e6 + 7, M1 = 1e9 + 7, M2 = 1e9 + 9, b1 = 127, b2 = 239;
int maxi1[N], maxi2[N], maxx[N];
pair <int, int> h1[N], h2[N];
pair <int, int> poww[N];
string best;

int mod(int x, int m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

pair <int, int> get_h(int l, int r) {
    int res1 = mod(h1[r].first - h1[l - 1].first * poww[r - l + 1].first, M1);
    int res2 = mod(h1[r].second - h1[l - 1].second * poww[r - l + 1].second, M2);
    return {res1, res2};
}

pair <int, int> get_h2(int l, int r) {
    int res1 = mod(h2[r].first - h2[l - 1].first * poww[r - l + 1].first, M1);
    int res2 = mod(h2[r].second - h2[l - 1].second * poww[r - l + 1].second, M2);
    return {res1, res2};
}

bool check(int n, int l, int r) {
    l++;
    r++;
    if (l < 1 || r > n) return 0;
    bool res =  get_h(l, r) == get_h2(n - r + 1, n - l + 1);
    //cout << l << ' ' << r << ' ' << res << endl;
    return res;
}

void solve(string s) {
    int n = s.length();
    string t = s;
    reverse(t.begin(), t.end());
    h1[0] = h2[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        h1[i].first = (h1[i - 1].first * b1 + s[i - 1] - 'a' + 1) % M1;
        h1[i].second = (h1[i - 1].second * b2 + s[i - 1] - 'a' + 1) % M2;
        h2[i].first = (h2[i - 1].first * b1 + t[i - 1] - 'a' + 1) % M1;
        h2[i].second = (h2[i - 1].second * b2 + t[i - 1] - 'a' + 1) % M2;
    }
    int ser = (n + 1) / 2;
    int len = 0;
    while (len != n && s[len] == s[n - len - 1]) {
        len++;
    }
    if (len == n) {
        best = s;
        return;
    }
    if (2 * len > (int) best.size()) {
        best = "";
        for (int i = 0; i < len; i++) best += s[i];
        for (int i = len - 1; i >= 0; i--) best += s[i];
        //cout << "! " << best << endl;
    }
    //cout << 43 << endl;
    int maxx = 2 * len;
    pair <int, int> kek;
    for (int i = ser - 1; i >= 0; i--) {
        int left = 1, right = n, mid;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (check(n, i - mid + 1, i + mid - 1)) left = mid;
            else right = mid;
        }
        int l = i - left, r = i + left;
        maxi1[i] = 2 * left - 1;
        //cout << i << ' ' << left << endl;
        if (l < len) {
            int curlen = maxi1[i] + 2 * (l + 1);
            if (curlen > maxx) {
                maxx = curlen;
                kek = {r, l};
                /*for (int j = 0; j < r; j++) {
                    best += s[j];
                }
                for (int j = l; j >= 0; j--) {
                    best += s[j];
                }*/
            }
            break;
        }
    }
    if (n % 2 == 1) ser--;
    for (int i = ser - 1; i >= 0; i--) {
        int left = 0, right = n, mid;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (check(n, i - mid + 1, i + mid)) left = mid;
            else right = mid;
        }
        int l = i - left, r = i + left + 1;
        //cout << "! " << i << ' ' << left << endl;
        //cout << left << endl;
        maxi2[i] = 2 * left;
        if (l < len) {
            int curlen = maxi2[i] + 2 * (l + 1);
            if (curlen > maxx) {
                maxx = curlen;
                kek = {r, l};
                /*for (int j = 0; j < r; j++) {
                    best += s[j];
                }
                for (int j = l; j >= 0; j--) {
                    best += s[j];
                }*/
            }
            break;
        }
    }
    if (maxx > (int) best.size()) {
        best = "";
        for (int j = 0; j < kek.first; j++) {
            best += s[j];
        }
        for (int j = kek.second; j >= 0; j--) {
            best += s[j];
        }
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    poww[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        poww[i].first = (poww[i - 1].first * b1) % M1;
        poww[i].second = (poww[i - 1].second * b2) % M2;
    }
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        best = s[0];
        solve(s);
        reverse(s.begin(), s.end());
        solve(s);
        cout << best << "\n";
    }
    return 0;
}