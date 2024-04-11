#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, m;
int p[N], a[N];
int pos[N];


int last[N];
int oneStep[2][N];
int ans[N][20];


int get(int L, int R) {
    int lg2 = log2(R - L + 1);
    return min(ans[L][lg2], ans[R - (1 << lg2) + 1][lg2]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> n >> m >> test;
    for(int i = 1; i <= n; i++) cin >> p[i]; p[n + 1] = p[1];
    for(int i = 1; i <= n; i++) pos[p[i]] = i;

    for(int i = 1; i <= m; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) last[i] = m + 1;

    oneStep[0][m + 1] = m + 1;
    for(int i = m; i >= 1; i--) {
        last[a[i]] = i;
        int nextV = p[pos[a[i]] + 1];
        oneStep[0][i] = last[nextV];
    }
    //for(int i = 1; i <= m; i++) cout << oneStep[0][i] << " ";
    //cout << '\n';

    for(int i = 1; i <= m; i++) ans[i][0] = i;

    for(int diff = n - 1; diff; diff >>= 1) {
        if (diff & 1) {
            for(int i = 1; i <= m; i++) ans[i][0] = oneStep[0][ans[i][0]];
        }
        for(int i = 1; i <= m + 1; i++) oneStep[1][i] = oneStep[0][i];
        for(int i = 1; i <= m + 1; i++)
            oneStep[0][i] = oneStep[1][oneStep[1][i]];
    }

    //for(int i = 1; i <= m; i++) cout << ans[i][0] << " ";
    //cout << '\n';

    for(int j = 1; j < 20; j++)
        for(int i = 1; i + (1 << j) - 1 <= m; i++)
            ans[i][j] = min(ans[i][j - 1], ans[i + (1 << (j - 1))][j - 1]);

    while (test--) {
        int L, R;
        cin >> L >> R;
        cout << (get(L, R) <= R);
    }
}