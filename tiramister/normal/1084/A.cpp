#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ans += a * i * 4;
    }

    cout << ans << endl;
    return 0;
}