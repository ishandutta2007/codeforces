#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int a[1010];

int main () {
    int k, n, m, sum = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= m + 1; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int tmp = a[m + 1] ^ a[i], cnt = 0;
        for (int j = 0; j < n; j++) {
            if (tmp & (1 << j)) cnt++;
        }
        if (cnt <= k) sum++;
    }
    cout << sum << endl;
}