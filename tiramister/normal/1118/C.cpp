#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt[1010];
    fill(cnt, cnt + 1010, 0);
    for (int i = 0; i < N * N; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }

    int ans[N][N];
    int itr = 1;
    for (int x = 0; x < N - x - 1; ++x) {
        for (int y = 0; y < N - y - 1; ++y) {
            while (itr <= 1000 && cnt[itr] < 4) ++itr;
            if (itr > 1000) {
                cout << "NO" << endl;
                return 0;
            }
            ans[x][y] = ans[N - x - 1][y] = ans[x][N - y - 1] = ans[N - x - 1][N - y - 1] = itr;
            cnt[itr] -= 4;
        }
    }

    if (N % 2 == 1) {
        itr = 1;
        for (int x = 0; x < N - x - 1; ++x) {
            while (itr <= 1000 && cnt[itr] < 2) ++itr;
            if (itr > 1000) {
                cout << "NO" << endl;
                return 0;
            }
            ans[x][N / 2] = ans[N - x - 1][N / 2] = itr;
            cnt[itr] -= 2;
        }

        for (int y = 0; y < N - y - 1; ++y) {
            while (itr <= 1000 && cnt[itr] < 2) ++itr;
            if (itr > 1000) {
                cout << "NO" << endl;
                return 0;
            }

            ans[N / 2][y] = ans[N / 2][N - y - 1] = itr;
            cnt[itr] -= 2;
        }

        itr = 1;
        while (itr <= 1000 && cnt[itr] == 0) ++itr;
        ans[N / 2][N / 2] = itr;
    }

    cout << "YES" << endl;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            cout << ans[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}