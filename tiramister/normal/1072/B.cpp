#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[2][N - 1];
    for (int b = 0; b < 2; ++b) {
        for (int i = 0; i < N - 1; ++i) {
            cin >> a[b][i];
        }
    }

    for (int f = 0; f < 4; ++f) {
        int t[N];
        fill(t, t + N, 0);
        t[0] = f;
        for (int i = 0; i < N - 1; ++i) {
            for (int k = 0; k < 2; ++k) {
                int b = (t[i] >> k) & 1;
                t[i + 1] += (a[b][i] & (1 << k));
            }
        }

        bool judge = true;
        for (int i = 0; i < N - 1; ++i) {
            if ((t[i] | t[i + 1]) != a[0][i]) judge = false;
        }
        for (int i = 0; i < N - 1; ++i) {
            if ((t[i] & t[i + 1]) != a[1][i]) judge = false;
        }

        if (judge) {
            cout << "YES" << endl;
            for (int i = 0; i < N; ++i) cout << t[i] << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}