#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 1e7 + 1;
bool isPrime[MAX];
int ans[MAX];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < MAX; i++) {
        ans[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int xx;
        scanf("%d", &xx);
        ans[xx]++;
    }
    for (int i = 0; i < MAX; i++) {
        isPrime[i] = true;
    }   
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < MAX; j += i) {
                isPrime[j] = false;
                ans[i] += ans[j];
            }
        } else {
            ans[i] = 0;
        }
    }
    for (int i = 1; i < MAX; i++) {
        ans[i] += ans[i - 1];
    }
    int m;
    scanf("%d", &m);
    for (int i =0 ; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (r > MAX - 1) {
            r = MAX - 1;
        }
        if (l > r) {
            printf("0\n");
            continue;
        }
        printf("%d\n", ans[r] - ans[l - 1]);
    }
    return 0;
}