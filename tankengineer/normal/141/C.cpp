#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3005;
int n, a[N], ord[N], used[N];

char name[N][15];

bool by_a(int i, int j) {
    return a[i] < a[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", name[i], a + i);
        ord[i] = i;
    }
    sort(ord, ord + n, by_a);
    memset(used, -1, sizeof(used));
    for (int i = n - 1; i >= 0; --i) {
        int u = ord[i], t = a[u], rank = i - t + 1, pos = 0;
        for (pos = 0; rank && pos < n; ++pos) {
            if (used[pos] == -1) {
                --rank;
            }
        }
        --pos;
        used[pos] = u;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == -1) {
            printf("-1\n");
            return 0;
        }
        a[used[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("%s %d\n", name[ord[i]], a[ord[i]]);
    }
    return 0;
}