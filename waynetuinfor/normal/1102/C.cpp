#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn];

int main() {
    int n, x, y; scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (x > y) {
        printf("%d\n", n);
        return 0;
    } 
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= x) v.push_back(a[i]);
    }
    int ans = 0;
    while (true) {
        int j = -1;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i] <= x) {
                if (j == -1 || v[i] > v[j]) j = i;
            }
        }
        if (j == -1) break;
        ++ans;
        v.erase(v.begin() + j);
        if ((int)v.size() == 0) break;
        j = -1;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (j == -1 || v[i] < v[j]) j = i;
        }
        v[j] += y;
    }
    printf("%d\n", ans);
    return 0;
}