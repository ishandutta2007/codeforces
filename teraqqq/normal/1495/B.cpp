#include <bits/stdc++.h>

using namespace std;

int mxOdd(int x) {
    return x % 2 ? x : x - 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> p(n); for(int& x : p) cin >> x;

    vector<int> up(n), upp(n+1), sup(n+1);
    vector<int> upl(n), upr(n);

    for (int i = 1; i < n; ++i) {
        upl[i] = p[i-1] > p[i] ? upl[i-1] + 1 : 0;
    }
    for (int i = n-1; i--; ) {
        upr[i] = p[i+1] > p[i] ? upr[i+1] + 1 : 0;
    }

    for (int i = 0; i < n; ++i) up[i] = max(upl[i], upr[i]);
    for (int i = 0; i < n; ++i) upp[i+1] = max(up[i], upp[i]);
    for (int i = n; i--; ) sup[i] = max(up[i], sup[i+1]);

    int ans = 0;
    for (int i = 1; i < n-1; ++i) {
        if (p[i-1] > p[i] || p[i+1] > p[i]) continue;
        int l = i, r = i;
        while (l > 0 && p[l-1] < p[l]) --l;
        while (r < n-1 && p[r+1] < p[r]) ++r;
        int distL = i - l, distR = r - i;

        int disjointWay = max(upp[l], sup[r+1]);
        disjointWay = max(disjointWay, upl[l]);
        disjointWay = max(disjointWay, upr[r]);
        if (disjointWay >= max(distL, distR)) continue;
        if (mxOdd(distL) >= distR || mxOdd(distR) >= distL) continue;
        if (distL % 2 && max(distL, upl[l]) >= distR) continue;
        if (distR % 2 && max(distR, upr[r]) >= distL) continue;
        ++ans;
    }

    cout << ans << endl;
}