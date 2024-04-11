#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x_) cerr << #x_ << " : " << x_ << endl
#define dbga(arr_, len_) {cerr << #arr_ << " : "; for (int _ = 0; _ < len_; _++) cerr << arr_[_] << " "; cerr << endl;}
#define dbgi(it_) {cerr << #it_ << " : "; for (const auto& _ : it_) cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr_, len_) (void)0
#define dbgi(it_) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

int n;

bool query(int x1, int y1, int x2, int y2) {
    if (x1 > x2) throw;
    if (y1 > y2) throw;
    if (x2 - x1 + y2 - y1 < n - 1) throw;
    printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
    fflush(stdout);
    char ans[10];
    scanf("%s", ans);
    return strcmp(ans, "YES") == 0;
}

void solve() {
    scanf("%d", &n);

    int xa = 0, ya = 0;
    string resa;
    for (int i = 0; i < n - 1; i++) {
        if (query(xa, ya + 1, n - 1, n - 1)) {
            ya++;
            resa += 'R';
        } else {
            xa++;
            resa += 'D';
        }
    }

    int xb = n - 1, yb = n - 1;
    string resb;
    for (int i = 0; i < n - 1; i++) {
        if (query(0, 0, xb - 1, yb)) {
            xb--;
            resb += 'D';
        } else {
            yb--;
            resb += 'R';
        }
    }
    reverse(resb.begin(), resb.end());

    if (xa != xb || ya != yb) {
        throw;
    }

    printf("! %s\n", (resa + resb).c_str());
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}