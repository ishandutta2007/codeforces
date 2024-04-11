#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

char s[MAXN];
int n;
vector<PII> f;
int qwq[MAXN];

int ln[MAXN];
int ps[MAXN];
int h, t;

int getpos_r(int l) {
    // cout << "??? getpos " << l << ": ";
    // for (int i = h; i < t; i++) cout << ln[i] << ' '; cout << "!!! ";
    int j = std::lower_bound(ln + h, ln + t, -l) - ln - h - 1;
    // cout << j << ' ' << ln[j] << ' ' << ps[j] << endl;
    return min(n, ps[j] + l - 1);
}

int getpos_l(int l) {
    int j = std::upper_bound(ln + h, ln + t, -l) - ln - h - 1;
    return max(1, ps[j] - l + 2);
}

int bf() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int cur = 0;
            int idx = i;
            while (idx <= j) {
                while (idx <= j && s[idx] == '0') idx++;
                if (idx > j) break;
                int p = idx;
                while (idx <= j && s[idx] == '1') idx++;
                cur = max(cur, idx - p);
            }
            ans += cur;
        }
    }
    return ans;
}

void solve(int casi){
    scanf("%d", &n);
    scanf("%s", s + 1);
    int idx = 1;
    while (idx <= n) {
        while (idx <= n && s[idx] == '0') idx++;
        if (idx > n) break;
        int p = idx;
        while (idx <= n && s[idx] == '1') idx++;
        f.emplace_back(p, idx - 1);
    }
    if (f.empty()) {
        puts("0"); return ;
    }
    ll ans = 0;
    h = 0, t = 1;
    ln[h] = -5 * n;
    ps[h] = 5 * n;
    // for (auto &x : f) {
    //     cout << x.first << ',' << x.second << ' ';
    // } cout << endl;
    for (int i = f.size() - 1; i >= 0; i--) {
        int l = f[i].first, r = f[i].second, lr = r - l + 1;
        for (int j = 1; j <= lr; j++) {
            int k = getpos_r(j);
            if (j == lr) {
                qwq[i] = (k - r);
            }
            else {
                ans += 1ll * (k - r) * j;
            }
            // cout << l << ' ' << r << ' ' << j << "     " << k << ' ' << ans << endl;
        }
        while (-ln[t - 1] <= lr) {
            t--;
        }
        ln[t] = -lr;
        ps[t] = l;
        t++;
    }
    // cout << ans << endl;
    h = 0, t = 1;
    ln[h] = -5 * n;
    ps[h] = -5 * n;
    for (int i = 0; i < f.size(); i++) {
        int l = f[i].first, r = f[i].second, lr = r - l + 1;
        for (int j = 1; j <= lr; j++) {
            int k = getpos_l(j);
            if (j == lr) {
                // cout << "??? " << qwq[i] << endl;
                ans += 1ll * (1ll * (l - k + 1) * (qwq[i] + 1) - 1) * j;
            }
            else {
                ans += 1ll * (l - k) * j;
            }
            // cout << l << ' ' << r << ' ' << j << "     " << k << ' ' << ans << endl;
        }
        while (-ln[t - 1] <= lr) {
            t--;
        }
        ln[t] = -lr;
        ps[t] = r;
        t++;
        // cout << "ans " << ans << endl;
    }
    int mxl = 0;
    // cout << ans << endl;
    for (int i = 0; i < f.size(); i++) {
        int l = f[i].first, r = f[i].second, lr = r - l + 1;
        mxl = max(mxl, lr);
        for (int j = 1; j <= lr; j++) {
            ans += 1ll * j * (lr - j + 1);
        }
    }

    printf("%lld\n", ans);
    // cout << bf() << endl;
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}