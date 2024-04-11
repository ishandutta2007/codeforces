#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> v;
        for (int i = 2; i * i <= n && v.size() < 3; ++i) {
            if (n % i == 0) {
                if (v.empty() || v.back() != i) {
                    v.push_back(i);
                    n /= i;
                }
            }
        }
        if (v.size() < 3 && n > 1 && (v.empty() || v.back() != n)) v.push_back(n), n = 1;
        v.back() *= n;
        if (v.size() < 3 || v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) puts("NO");
        else puts("YES"), printf("%d %d %d\n", v[0], v[1], v[2]);
    }
    return 0;
}