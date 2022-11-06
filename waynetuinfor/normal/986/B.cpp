#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
bool v[maxn];

long long cycle(const vector<int> &a) {
    memset(v, false, sizeof(v));
    int c = 0;
    for (int i = 0; i < a.size(); ++i) if (!v[a[i]]) {
        int l = 0;
        int x = a[i];
        for (; !v[x]; x = a[x], ++l) v[x] = true;
        ++c;
    }
    return c;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), a[i]--;
    int c = cycle(a); 
    if ((n - c) % 2 == (3 * n) % 2) puts("Petr");
    else puts("Um_nik");
    return 0; 
}