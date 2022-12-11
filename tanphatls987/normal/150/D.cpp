#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 10;
const int N = 160;

string s;
int n, w[N];
int h[N][N][N][2];
int f[N][N][N][2];
int DP(int len, int L, int R, int drop) {
    if (h[len][L][R][drop]) return f[len][L][R][drop];
    h[len][L][R][drop] = 1;

    int &ans = f[len][L][R][drop];
    ans = -inf;
    if (L > R) {
        ans = ((w[len] == -1) ? -inf : w[len]);
        return ans;
    }
    ///add 2 tail
    if (L < R && s[L] == s[R] && len % 2 == 0)
        ans = max(ans, DP(len + 2, L + 1, R - 1, 0));
    ///add 1 char
    if (len % 2 == 0) {
        ans = max(ans, max(DP(len + 1, L + 1, R, 0), DP(len + 1, L, R - 1, 0)));
    }
    ///drop option
    if (drop == 1) {
        assert(len == 0);
        ans = max(ans, max(DP(0, L + 1, R, 1), DP(0, L, R - 1, 1)));
    } 
    ///use from left
    for(int mid = L; mid <= R; mid++) {
        ans = max(ans, DP(len, mid + 1, R, drop) + DP(0, L, mid, 0));
        ans = max(ans, DP(len, L, mid - 1, drop) + DP(0, mid, R, 0));
    }
    //cout << len << " " << L << " " << R << " " << drop << " " << ans << '\n';
    return ans;
}

void prepare() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    cin >> s;
    s = " " + s;
}
int main() {
    prepare();
    cout << DP(0, 1, n, 1);
}