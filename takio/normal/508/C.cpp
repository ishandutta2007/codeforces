#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#define LL long long
#define pii pair <int, int>

using namespace std;

int cnt[330];

int main () {
    int n, t, r;
    cin >> n >> t >> r;
    if (t < r) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0, a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        int tmp = r - cnt[a];
        if (tmp <= 0) continue;
        res += tmp;
        for (int j = a; j <= 300 && j <= a + t - tmp; j++) {
            cnt[j] += tmp;
        }
        for (int j = a + t - tmp + 1, k = tmp - 1; j <= 300 && k; j++, k--) {
            cnt[j] += k;
        }
//        for (int j = 1; j <= 10; j++) cout << cnt[j] << ' '; cout << endl;
    }
    cout << res << endl;
}