#include <cstdio>

using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int ret = 0;
    while(a <= b) {
        ret++;
        a *= 3;
        b *= 2;
    }
    printf("%d\n", ret);
}