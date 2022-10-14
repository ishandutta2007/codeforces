#include <stdio.h>
int main() {
    int tt; scanf("%d", &tt);
    for(int j = 0; j < tt; ++j) {
        int x;
        scanf("%d", &x);
        printf("%d\n", (x+1)/10);
    }
}