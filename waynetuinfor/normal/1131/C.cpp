#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i += 2) printf("%d ", a[i]);
    vector<int> b;
    for (int i = 1; i < n; i += 2) b.push_back(a[i]);
    reverse(b.begin(), b.end());
    for (int i = 0; i < (int)b.size(); ++i) printf("%d ", b[i]);
    puts("");
}