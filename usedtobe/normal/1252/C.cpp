#include<bits/stdc++.h>
using namespace std;
long long n;
int main() {
    int cc = 0;
    cin >> n;
    long long t = n, ans = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (t % i == 0) {
            ++cc;
            while (t % i == 0) t /= i;
            ans = i;
        }
    }
    if (t > 1) ++cc;
    if (cc > 1) {
        ans = 1;
    }
    cout << ans;
    return 0;
}