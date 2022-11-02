#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = 1, left = m;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (left >= a) {
            left -= a;
        } else {
            ++ans, left = m - a;
        }
    }
        printf("%d\n", ans);
    return 0;
}