#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int N;
    double s;
    cin >> N >> s;

    int cnt[N];
    fill(cnt, cnt + N, 0);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        ++cnt[a - 1];
        ++cnt[b - 1];
    }

    double d = 0;
    for (int v = 0; v < N; ++v) {
        if (cnt[v] == 1) ++d;
    }

    double ans = s / d * 2;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}