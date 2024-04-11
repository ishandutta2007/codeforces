#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int cnt[N], filled = 0;
    fill(cnt, cnt + N, 0);

    for (int q = 0; q < M; ++q) {
        int a;
        cin >> a;
        --a;
        if (cnt[a] == 0) ++filled;
        ++cnt[a];

        if (filled < N) {
            cout << 0;
        } else {
            cout << 1;
            for (int i = 0; i < N; ++i) {
                --cnt[i];
                if (cnt[i] == 0) --filled;
            }
        }
    }
    cout << endl;
    return 0;
}