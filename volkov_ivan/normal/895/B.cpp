#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    long long n, k, x;
    cin >> n >> x >> k;
    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld ", &a[i]);
    }
    long long ans = 0;
    sort(a, a + n);
    long long l = 0, r = 0, last = -1, maximum, minimum;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            ans += last;
            continue;
        }
        maximum = (ceil(double(a[i]) / x)) * x + k * x - 1;
        minimum = (ceil(double(a[i]) / x)) * x + (k - 1) * x;
        if (minimum < a[i]) minimum = a[i];
        //cout << a[i] << ' ' << minimum << ' ' << maximum << endl;
        while (l != n && a[l] < minimum) l++;
        while (r != n && a[r] <= maximum) r++;
        ans += r - l;
        last = r - l;
    }
    cout << ans << endl;
    return 0;
}