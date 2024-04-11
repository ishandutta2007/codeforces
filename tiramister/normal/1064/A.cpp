#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[3];
    for (int i = 0; i < 3; ++i) cin >> a[i];
    sort(a, a + 3);
    int rack = a[2] - (a[0] + a[1]);
    cout << max(0, rack + 1) << endl;
    return 0;
}