#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    printf("%d\n", min(*max_element(a.begin(), a.end() - 1) - *min_element(a.begin(), a.end() - 1),
                       *max_element(a.begin() + 1, a.end()) - *min_element(a.begin() + 1, a.end())));
}