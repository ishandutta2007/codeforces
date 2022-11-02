#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 1 || m == 1) {
        printf("%d\n", n * m);
        return 0;
    }
    if (n == 2 || m == 2) {
        int t = n + m - 2;
        int ans = t / 4 * 4 + min(t % 4, 2) * 2;
        printf("%d\n", ans);
        return 0;
    }
    int cnt = ((n + 1) / 2) * ((m + 1) / 2) + (n / 2) * (m / 2);
    printf("%d\n", cnt);
    return 0;
}