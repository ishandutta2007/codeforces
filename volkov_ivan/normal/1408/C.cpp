#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;
    int a[n + 2];
    long double t1[n + 2], t2[n + 2];
    int speed1[n + 2], speed2[n + 2];
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0;
    a[n + 1] = l;
    t1[0] = 0;
    speed1[0] = 1;
    t2[n + 1] = 0;
    speed2[n + 1] = 1;
    long double t = 0;
    int lst = 0, sp = 1;
    long double one = 1;
    for (int i = 1; i <= n + 1; i++) {
        long double tm = (one * (a[i] - lst)) / sp + t;
        t1[i] = tm;
        t = tm;
        sp++;
        speed1[i] = sp;
        lst = a[i];
    }
    lst = l;
    sp = 1;
    t = 0;
    for (int i = n; i >= 0; i--) {
        long double tm = (one * (lst - a[i])) / sp + t;
        t = tm;
        t2[i] = tm;
        sp++;
        speed2[i] = sp;
        lst = a[i];
    }
    int cur = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (t2[i] <= t1[i]) {
            cur = i;
            break;
        }
    }
    long double tt = max(t2[cur], t1[cur - 1]);
    //cout << tt << ' ' << t1[cur - 1] << ' ' << t2[cur] << endl;
    long double len = (a[cur] - a[cur - 1]);
    len -= speed1[cur - 1] * (tt - t1[cur - 1]);
    len -= speed2[cur] * (tt - t2[cur]);
    //cout << cur << ' ' << len << ' ' << t1[cur] << ' ' << t2[cur] << ' ' << t1[cur - 1] << endl;
    tt += (one * len) / (speed1[cur - 1] + speed2[cur]); 
    cout << fixed << tt << "\n";
}

signed main() {
    cout.precision(20);
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}