#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    deque<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    while (a.size() && a.front() <= k) a.pop_front();
    while (a.size() && a.back() <= k) a.pop_back();
    printf("%d\n", n - a.size());
}