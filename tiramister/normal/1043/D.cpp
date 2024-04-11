#include <iostream>

using namespace std;
using ll = long long;

const int INF = 1 << 25;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int a[M][N + 1], rev[M][N];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
            --a[i][j];
            rev[i][a[i][j]] = j;
        }
        a[i][N] = INF + i;
    }

    ll ans = 0;
    int b;
    for (b = 0; b < N;) {
        int itr[M];
        for (int i = 0; i < M; ++i) {
            itr[i] = rev[i][a[0][b]];
        }

        bool judge = true;
        while (judge) {
            for (int i = 0; i < M; ++i) {
                ++itr[i];
                if (itr[i] >= N) judge = false;
            }

            if (!judge) break;
            for (int i = 0; i < M - 1; ++i) {
                if (a[i][itr[i]] != a[i + 1][itr[i + 1]]) judge = false;
            }
        }

        ll len = itr[0] - b;
        ans += len * (len + 1) / 2;
        b = itr[0];
    }

    cout << ans << endl;
    return 0;
}