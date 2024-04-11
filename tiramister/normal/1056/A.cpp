#include <iostream>

using namespace std;

const int S = 100;

int main() {
    int N;
    cin >> N;

    int cnt[S];
    fill(cnt, cnt + S, 0);
    for (int i = 0; i < N; ++i) {
        int r;
        cin >> r;
        for (int j = 0; j < r; ++j) {
            int a;
            cin >> a;
            ++cnt[a - 1];
        }
    }

    for (int s = 0; s < S; ++s) {
        if (cnt[s] == N) cout << s + 1 << " ";
    }
    cout << endl;
    return 0;
}