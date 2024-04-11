#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 7, INF = 1e18;

struct line{
    int k, b;
    line() {}
    line(int k, int b): k(k), b(b) {}
    long double intersec(line l) {
        long double u = l.b - b;
        long double d = k - l.k;
        return u / d;
    }
};

signed a[N];
long double pref[N], b[N];
pair <long double, int> ans[N];
vector <pair <long double, line>> st;

pair <long double, int> add(line l) {
    /*if (st.empty()) {
        st.push_back({INF, l});
        return {-1, -1};
    }*/
    pair <long double, int> res = {1, 1};
    while (!st.empty()) {
        long double x = l.intersec(st.back().second);
        if (x < st.back().first) {
            res = {x, -st.back().second.k};
            st.push_back({x, l});
            break;
        }
        st.pop_back();
    }
    if (st.empty()) st.push_back({INF, l});
    return res;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(11);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
    for (int i = n; i >= 0; i--) {
        ans[i] = add(line(-i, pref[i]));
    }
    for (int i = 1; i <= n; i++) {
        //cout << ans[i - 1].second << endl;
        for (int j = i; j <= ans[i - 1].second; j++) b[j] = ans[i - 1].first;
        i = ans[i - 1].second;
    }
    for (int i = 1; i <= n; i++) {
        cout << fixed << b[i] << '\n';
    }
    return 0;
}