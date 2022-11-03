#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N + 2];
    a[0] = 0, a[N + 1] = 1001;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    int ans = 0, cnt = 1;
    for (int i = 0; i <= N; ++i) {
        if (a[i + 1] - a[i] == 1) {
            ++cnt;
        } else {
            cnt = 1;
        }
        ans = max(ans, cnt);
    }

    cout << min(N - 1, max(0, ans - 2)) << endl;
    return 0;
}