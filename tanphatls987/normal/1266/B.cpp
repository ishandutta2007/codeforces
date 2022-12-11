#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
const int MOD = 998244353;

int f[N];


void prepare() {
    f[1] = 1;
    for(int i = 14; i < N; i++) {
        f[i] = f[i - 13] | f[i - 14];
    }
}
string solve(long long val) {
    for(int use = 1; use <= 6; use++) {
        long long rem = val - 21 + use;
        if (rem >= 0 && rem % 14 == 0) return "YES";
    }
    return "NO";
}
int main() {
    prepare();
    int test;
    cin >> test;
    while (test--) {
        long long val;
        cin >> val;
        cout << solve(val) << '\n';
    }
}