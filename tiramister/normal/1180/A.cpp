#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 1;
    for (int i = 1; i < N; ++i) {
        ans += i * 4;
    }
    cout << ans << endl;
    return 0;
}