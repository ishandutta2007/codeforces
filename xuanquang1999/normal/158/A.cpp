using namespace std;
#include <cstdio>
#include <algorithm>
#define fto(i, l, r) for(int i = l; i <= r; ++i)

int a[55], n, k;

int main() {
// asdfsadas
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        if (a[i] >= a[k] && a[i] > 0) ++cnt;
    printf("%d", cnt);
}