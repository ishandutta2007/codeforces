#include <iostream>

using namespace std;

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

int main() {
    int N, K;
    cin >> N >> K;

    int cnt[100];
    fill(cnt, cnt + 100, 0);

    int kind = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        --a;
        if (cnt[a] == 0) ++kind;
        ++cnt[a];
    }

    int s = 0;
    for (int i = 0; i < 100; ++i) {
        s = max(s, iceil(cnt[i], K));
    }

    cout << s * K * kind - N << endl;
    return 0;
}