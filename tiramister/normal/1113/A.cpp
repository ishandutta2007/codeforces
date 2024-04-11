#include <iostream>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    int ans = N - 1;
    for (int i = N - V; i >= 1; --i) ans += i - 1;
    cout << ans << endl;
    return 0;
}