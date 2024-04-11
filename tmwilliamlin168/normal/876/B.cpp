#include <bits/stdc++.h>

#define ll long long
using namespace std;



int main() {
#ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<int> a(n);
    map<int, vector<int>> q;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        q[a[i] % m].push_back(a[i]);
    }
    for (auto it : q) {
        if (it.second.size() >= k) {
            printf("Yes\n");
            for (int i = 0; i < k; ++i)
                printf("%d ", it.second[i]);
            return 0;
        }
    }
    printf("No");

    return 0;
}