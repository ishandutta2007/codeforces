#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    long long ans = -1;
    vector<int> v;
    for (long long i = 1; i * i <= n; ++i) {
        v.push_back(i);
        v.push_back(n / i);
    }
    for (int i = 0; i < (int)v.size(); ++i) {
        long long a = v[i], b = max((long long)1, k - a + 2);
        if (a <= n && b <= m) {
            ans = max(ans, (n / a) * (m / b));
        }
    }
    cout << ans << endl;
    return 0;
}