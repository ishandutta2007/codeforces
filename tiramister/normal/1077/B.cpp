#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1) {
            ++ans;
            a[i + 1] = 0;
        }
    }

    cout << ans << endl;
    return 0;
}