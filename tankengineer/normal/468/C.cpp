#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long a, bar;

long long cal(long long n) {
    long long ret = 0, MUL = 1, ori = n;
    while (n) {
        int d = n % 10;
        ret += (45 * (n / 10) + d * (d - 1) / 2) * MUL + d * (ori % MUL + 1);
        MUL *= 10;
        n /= 10;
    }
    return ret;
}

int main() {
    cin >> a;
    if (a == 1) {
        printf("1 1\n");
        return 0;
    }
    bar = 1;
    while (cal(bar) < a) {
        bar *= 10;
    }
    /*
    for (int i = 0; i <= 100; ++i) {
        cout << i << ' ' << cal(i) << endl;
    }
    */
    long long n = 0;    
    while (bar /= 10) {
        while (cal(n + bar) < a) {
            n += bar;
        }
    }
    long long l = 0, cl = cal(l), r = n, cr = cal(r);
    while (cr - cl != a) {
        if (cr - cl > a) {
            ++l, cl = cal(l);
        } else {
            ++r, cr = cal(r);
        }
    }
    cout << l + 1 << ' ' << r << endl;
    return 0;
}