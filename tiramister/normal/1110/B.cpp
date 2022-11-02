#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int b[n];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int s[n - 1];
    for (int i = 0; i < n - 1; ++i) s[i] = b[i + 1] - b[i] - 1;

    sort(s, s + n - 1);
    cout << n + accumulate(s, s + n - k, 0) << endl;
    return 0;
}