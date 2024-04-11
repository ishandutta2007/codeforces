#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int x, y;
    scanf("%d%d", &x, &y);

    int a[3] = {y, y, y}, ans = 0;
    while (a[0] < x) {
        ++ans;
        a[0] = a[1]+a[2]-1;
        sort(a, a+3);
    }

    printf("%d", ans);
}