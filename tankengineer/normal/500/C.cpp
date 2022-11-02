#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

int n, m;

int w[N], ord[N], first[N], r[N];

bool byFirst(int i, int j) {
    return first[i] < first[j];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", w + i);
        first[i] = m;
        ord[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", r + i);
        --r[i];
        first[r[i]] = min(first[r[i]], i);
    }
    sort(ord, ord + n, byFirst); 
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int pos = -1;
        for (int j = 0; j < n; ++j) {
            if (ord[j] == r[i]) {
                pos = j;
                break;
            }
            ans += w[ord[j]];
        }
        for (int j = pos; j > 0; --j) {
            swap(ord[j], ord[j - 1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}