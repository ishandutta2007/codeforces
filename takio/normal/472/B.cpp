#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int a[2010];

int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    int res = 0;
    for (int i = n; i >= 1; i -= k) {
        res += (a[i] - 1) * 2;
    }
    cout << res << endl;
}