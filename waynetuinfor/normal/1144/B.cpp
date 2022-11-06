#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
int a[maxn];
vector<int> v[2];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) v[a[i] % 2].push_back(a[i]);
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    int ans = 0;
    for (int s = 0; s < 2; ++s) {
        vector<int> w[2] = {v[0], v[1]};
        int sum = 0;
        int x = s;
        while (!w[x].empty()) {
            sum += w[x].back();
            w[x].pop_back();
            x ^= 1;
        }
        ans = max(ans, sum);
    } 
    printf("%d\n", accumulate(a, a + n, 0) - ans);
    return 0;
}