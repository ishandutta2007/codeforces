#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define LL long long
#define ULL unsigned long long
using namespace std;

int a[500010];

int main () {
    int n;
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        sum += a[i];
    }
    if (sum % 3) {
        cout << 0 << endl;
        return 0;
    }
    LL t = sum / 3;
    sum = 0;
    LL s1 = 0, res = 0;
//    cout << t << endl;
    for (int i = 1; i < n; i++) {
        sum += a[i];
        if (sum == 2 * t) res += s1;
        if (sum == t) s1++;
    }
    cout << res << endl;
}