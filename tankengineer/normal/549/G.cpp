#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int n, a[N], b[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        a[i] += i;
    }
    sort(a, a + n);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] -= i;
        if (b[i] < 0) {
            flag = true;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (b[i] < b[i - 1]) {
            flag = true;
        }
    }
    if (flag) {
        puts(":(");
    } else {
        for (int i = 0; i < n; ++i) {
            printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}