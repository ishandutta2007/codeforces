#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;

LL t[110];

int main () {
    int a, b, c, tn = 0, cnt = 0;
    cin >> a >> b >> c;
    for (int i = 1; i <= 100; i++) {
        LL res = 1;
        for (int j = 1; j <= a; j++) {
            res *= i;
        }
        res *= b;
        res += c;
        if (res > 1e9) continue;
        LL tmp = res, sum = 0;
//        cout << res << endl;
        while (res) {
            sum += res % 10;
            res /= 10;
        }
        if (sum == i) t[++tn] = tmp, cnt++;
    }
    cout << cnt << endl;
    sort (t + 1, t + 1 + tn);
    for (int i = 1; i <= tn; i++) {
        if (i != 1) cout << ' ';
        cout << t[i];
    }
}