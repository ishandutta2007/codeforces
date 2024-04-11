#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 30005;

int n, t, a[N];

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    --t;
    int cur = 0;
    while (cur != t && cur != n - 1) {
        cur += a[cur];
    }
    puts(cur == t ? "YES" : "NO");
    return 0;
}