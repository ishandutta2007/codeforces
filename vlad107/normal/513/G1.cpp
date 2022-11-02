#include <bits/stdc++.h>

using namespace std;

int n, k, a[111], sum, cnt;

void rec(int x) {
    if (x == k) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) sum += (a[i] > a[j]);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int e = i; e <= j; e++) {
                int o = j - (e - i);
                if (o > e) swap(a[o], a[e]);
            }
            rec(x + 1);
            for (int e = i; e <= j; e++) {
                int o = j - (e - i);
                if (o > e) swap(a[o], a[e]);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    rec(0);
    int cnt = 0;
    for (int i = 0; i < n; i++) for (int j = i; j < n; j++) cnt++;
    int cur = 1;
    for (int i = 0; i < k; i++) cur *= cnt;
    printf("%.10f\n", sum * 1.0 / cur);
}