#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int t[1000010];

int main () {
    int n = 1e6;
    for (long long i = 2; i <= n; i++) {
        for (long long j = i * i; j <= n; j += i)
            t[j] = 1;
    }
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (t[i] && t[n - i]) {
            cout << i << ' ' << n - i;
            return 0;
        }
    }
}