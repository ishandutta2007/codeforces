#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

int a, b, c;

ll first0(int b1_count, int b1_sum, int b0_l, int b0_r, vector<int> t0) {
    int ptr = 0, sec = 0;

    ll w = 0, ans = 0;

    int last0 = -2;
    int reason = -2;

    while (true) {
        while (ptr < size(t0) && t0[ptr] == 1) ++ptr;
        if (ptr == size(t0)) {
            if (b0_l > 1) {
                b0_l--;
                last0 = -1; // other
                ckmax(ans, w += a);
            } else if (b0_r > 1) {
                b0_r--;
                last0 = -3;
                ckmax(ans, w += a);
            } else {
                break;
            }
        } else {
            last0 = ptr;
            t0[ptr]--;
            ckmax(ans, w += a);
        }

        if (b1_count < b1_sum) {
            b1_sum--;
            ckmax(ans, w += b);
            last0 = -2;
        } else {
            break;
        }
    }

    w -= a;
    if (last0 == -1) b0_l++;
    else if (last0 == -3) b0_r++;
    else if (last0 == -2) w += a;
    else t0[ptr]++;

    // cerr << "fint0 " << w << endl;

    ptr = 0;
    while (ptr < size(t0) && t0[ptr] == 1) ++ptr;
    int save = ptr;

    while (true) {
        if (ptr > 0) {
            ptr--;
            b1_count--;
            w -= c;
        } else if (b0_l > 1) {
            b0_l--;
            w += a;
        } else if (b0_r > 1) {
            b0_r--;
            w += a;
        } else if (b0_l > 0) {
            b0_l--;
            w -= c;
        } else if (b0_r > 0) {
            b0_r--;
            w -= c;
        } else {
            break;
        }

        ckmax(ans, w);

        if (b1_count < b1_sum) {
            b1_sum--;
            ckmax(ans, w += b);
            if (save != size(t0)) ckmax(ans, w + a);
        } else {
            break;
        }
    }

    return ans;
}

ll first1(int b1_count, int b1_sum, int b0_l, int b0_r, vector<int> t0) {
    int ptr = 0, sec = 0;

    ll w = 0, ans = 0;

    int last0 = -2;
    int reason = -2;

    while (true) {
        if (b1_count < b1_sum) {
            b1_sum--;
            ckmax(ans, w += b);
            last0 = -2;
        } else {
            break;
        }

        while (ptr < size(t0) && t0[ptr] == 1) ++ptr;
        if (ptr == size(t0)) {
            if (b0_l > 1) {
                b0_l--;
                last0 = -1; // other
                ckmax(ans, w += a);
            } else if (b0_r > 1) {
                b0_r--;
                last0 = -3;
                ckmax(ans, w += a);
            } else {
                break;
            }
        } else {
            last0 = ptr;
            t0[ptr]--;
            ckmax(ans, w += a);
        }
    }

    w -= a;
    if (last0 == -1) b0_l++;
    else if (last0 == -3) b0_r++;
    else if (last0 == -2) w += a;
    else t0[ptr]++;

    ptr = 0;
    while (ptr < size(t0) && t0[ptr] == 1) ++ptr;
    int save = ptr;

    while (true) {
        if (ptr > 0) {
            b1_count--;
            ptr--;
            w -= c;
        } else if (b0_l > 1) {
            b0_l--;
            w += a;
        } else if (b0_r > 1) {
            b0_r--;
            w += a;
        } else if (b0_l > 0) {
            b0_l--;
            w -= c;
        } else if (b0_r > 0) {
            b0_r--;
            w -= c;
        } else {
            break;
        }

        ckmax(ans, w);

        if (b1_count < b1_sum) {
            b1_sum--;
            ckmax(ans, w += b);
            if (save != size(t0)) ckmax(ans, w + a);
        } else {
            break;
        }
    }

    return ans;
}

void solve() {

    int n; cin >> n >> a >> b >> c;
    string s; cin >> s;

    int b1_count = 0, b1_sum = 0;
    int b0_l = 0, b0_r = 0;
    vector<int> t0;

    for (int i = 0; i < n; ) {
        int j = i;
        while (i < n && s[i] == s[j]) ++i;

        if (s[j] == '0') {
            if (j == 0) {
                b0_l = i - j;
            } else if (i == n) {
                b0_r = i - j;
            } else {
                t0.push_back(i - j);
            }
        } else {
            b1_count++;
            b1_sum += i - j;
        }
    }

    sort(t0.begin(), t0.end());

    ll res = max(first0(b1_count, b1_sum, b0_l, b0_r, t0),
                 first1(b1_count, b1_sum, b0_l, b0_r, t0));

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}