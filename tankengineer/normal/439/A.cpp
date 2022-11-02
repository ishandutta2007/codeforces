#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, d;

int sum = 0;

int main() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        sum += a;
    }
    int cnt = 2 * (n - 1);
    sum += 5 * cnt;
    while (sum + 5 <= d) {
        sum += 5, cnt += 1;
    }
    printf("%d\n", sum <= d ? cnt : -1);
    return 0;
}