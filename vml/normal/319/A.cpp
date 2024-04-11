#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

const long long inf = 1000000007;

long long binary_pow(long long st) {
    if (st == 0) {
        return 1;
    }
    if (st % 2 == 1) {
        return (binary_pow(st - 1) * 2) % inf;
    }
    long long ans = binary_pow(st / 2);
    return (ans * ans) % inf;
}

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            long long res = binary_pow(n - i - 1);
            ans = (ans + (binary_pow(i) * ((res * res) % inf)) % inf) % inf;
        }
    }
    printf("%d", ans);
    return 0;
}