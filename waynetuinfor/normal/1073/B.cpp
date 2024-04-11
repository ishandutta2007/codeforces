#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
bool v[maxn];
int a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); 
        --a[i];
        v[a[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        --b[i];
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (!v[b[i]]) {
            printf("0 ");
            continue;
        }
        int cnt = 0;
        while (j < n && a[j] != b[i]) {
            ++cnt;
            v[a[j]] = false;
            ++j;
        }
        ++cnt;
        v[a[j]] = false;
        ++j;
        printf("%d ", cnt);
    }
    puts("");
    return 0;
}