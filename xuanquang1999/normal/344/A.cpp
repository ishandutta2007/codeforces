#include <iostream>

using namespace std;

int main() {
    int n, last;
    cin >> n >> last;

    int ans = 1;
    for(int i = 2; i <= n; ++i) {
        int cur;
        cin >> cur;
        if (cur != last) ++ans;
        last = cur;
    }

    cout << ans;
}