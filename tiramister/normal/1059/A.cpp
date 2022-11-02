#include <iostream>

using namespace std;

int main() {
    int N, L, A;
    cin >> N >> L >> A;

    int ans = 0, pre = 0;
    for (int i = 0; i < N; ++i) {
        int t, l;
        cin >> t >> l;
        ans += (t - pre) / A;
        pre = t + l;
    }
    ans += (L - pre) / A;
    cout << ans << endl;
    return 0;
}