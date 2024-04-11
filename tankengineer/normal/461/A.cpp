#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    long long ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        ans += (long long)v[i] * (i + 2);
    }
    cout << ans - v.back() << endl;
    return 0;
}