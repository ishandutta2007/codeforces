#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int pa = 0, pb = 0, ans = 1;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        ans += max(0, min(a, b) - max(pa, pb) + 1);
        if (pa == pb) --ans;
        pa = a, pb = b;
    }

    cout << ans << endl;
    return 0;
}