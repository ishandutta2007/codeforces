#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 3e5 + 10;


int n, a[N];
int trL[N][20], trR[N][20];
ii fL[N][20], fR[N][20];
ii acL[N][20], acR[N][20];
int lg2[N];


ii get(ii a[][20], int L, int R, function<bool(ii, ii)> comp) {
    int len = lg2[R - L + 1];
    return min(a[L][len], a[R - (1 << len) + 1][len], comp);
}

void prepare() {
    for(int i = 2; i < N; i++) lg2[i] = lg2[i / 2] + 1;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) a[i + n] = a[i + 2 * n] = a[i];

    a[0] = a[3 * n + 1] = 5 * (n + 1);
    for(int i = 0; i <= 3 * n + 1; i++) {
        fL[i][0] = ii(max(i - a[i], 0), i);
        fR[i][0] = ii(min(i + a[i], 3 * n + 1), i);
    }
    for(int j = 1; j < 20; j++){
        for(int i = 0; i <= 3 * n + 1 - (1 << j) + 1; i++){
            fL[i][j] = min(fL[i][j - 1], fL[i + (1 << (j - 1))][j - 1]);
            fR[i][j] = max(fR[i][j - 1], fR[i + (1 << (j - 1))][j - 1]);
        }
    }

    int s[N];
    s[0] = 1;
    s[1] = 0;

    for(int i = 1; i <= 3 * n + 1; i++) {
        while (i - a[i] <= s[s[0]] - a[s[s[0]]]) s[0]--;
        trL[i][0] = *lower_bound(s + 1, s + s[0] + 1, i - a[i]);
        s[++s[0]] = i;
    }
    trL[0][0] = 0;
    for(int j = 1; j < 20; j++)
        for(int i = 0; i <= 3 * n; i++)    
            trL[i][j] = trL[trL[i][j - 1]][j - 1];

    s[0] = 1;
    s[1] = 3 * n + 1;
    for(int i = 3 * n; i >= 0; i--) {
        while (i + a[i] >= s[s[0]] + a[s[s[0]]]) s[0]--;
        trR[i][0] = *lower_bound(s + 1, s + s[0] + 1, i + a[i], greater<int>());
        s[++s[0]] = i;
    }

    trR[3 * n + 1][0] = 3 * n + 1;
    for(int j = 1; j < 20; j++)
        for(int i = 0; i <= 3 * n + 1; i++)    
            trR[i][j] = trR[trR[i][j - 1]][j - 1];

    for(int i = 0; i <= 3 * n + 1; i++) {
        acL[i][0] = get(fL, i, min(i + a[i], 3 * n + 1), less<ii>());  
        acR[i][0] = get(fR, max(0, i - a[i]), i, greater<ii>());
    }
    for(int j = 1; j < 20; j++)
        for(int i = 0; i <= 3 * n + 1; i++) {
            acL[i][j] = min(acL[i][j - 1], acL[trR[i][j - 1]][j - 1]);
            acR[i][j] = max(acR[i][j - 1], acR[trL[i][j - 1]][j - 1]);
        }

}
bool check(int stL, int stR, int len) {
    if (len == 0) {
        return stR - stL + 1 >= n;
    }
    len--;
    int reachL = stL;
    for(int i = 0; i < 20; i++) if (len & (1 << i)) {
        reachL = trL[reachL][i];
    }
    reachL -= a[reachL];

    int reachR = stR;
    for(int i = 0; i < 20; i++) if (len & (1 << i)) {
        reachR = trR[reachR][i];
    }
    reachR += a[reachR];
    return reachR - reachL + 1 >= n;
}
int expand(int st) {
    int ans = 0;
    st += n;
    int aL = st, aR = st;
    while (1) {
        assert(aL <= aR);
        int curL = aL, curR = aR;
        int add = 0;
        for(int i = 19; i >= 0; i--) {
            if (acR[curL][i].X <= aR && acL[curR][i].X >= aL) {
                add += 1 << i;
                curL = trL[curL][i];
                curR = trR[curR][i];
            }
        }
        
        if (check(aL, aR, add)) {
            int L = 1, R = add;
            while (L <= R) {
                int mid = (L + R) / 2;
                if (check(aL, aR, mid)) R = mid - 1;
                else L = mid + 1;
            }
            return ans + L;
        }
        ans += add;
        aR = curR, aL = curL;
        while (1) {
            ans++;
            ii potR = get(fR, aL, st, greater<ii>());
            ii potL = get(fL, st, aR, less<ii>());
            bool flip = potR.X > aR || potL.X < aL;

            int rR = max(potR.X, aR + a[aR]), rL = min(potL.X, aL - a[aL]);
            ///cout << st << " " << aL << " " << aR << " " << ans << " "<< rR << " "<<rL << '\n';
            if (rR - rL + 1 >= n) return ans;
            int nR = min(trR[potR.Y][0], trR[aR][0],
                [](int x, int y) {
                    return x + a[x] > y + a[y];
                });
            int nL = min(trL[potL.Y][0], trL[aL][0],
                [](int x, int y) {
                    return x - a[x] < y - a[y];
                });
            aL = nL, aR = nR;
            if (!flip) break;
        }
    }
    //cout <<'\n';
}
void solve() {
    if (n == 1) {
        cout << "0";
        return;
    }
    for(int st = 1; st <= n; st++) {
        cout << expand(st) << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    solve();
}