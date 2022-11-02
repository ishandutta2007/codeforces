#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
bool choose[N];

void dye(int n, int p) {
    for (int i = 0; i <= n; ++i) {
        if (i % p == 0) {
            choose[i] = true;
        }
    }
}

int main() {
    int n;
    int a, b, c, d;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    dye(n, a), dye(n, b), dye(n, c), dye(n, d);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!choose[i]) {
            ++cnt;
        }
    }
    printf("%d\n", n - cnt);
    return 0;
}