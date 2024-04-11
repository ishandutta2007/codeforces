#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    printf("%d\n", (6 * n - 1) * k);
    int i = 1;
    while (n--) {
        printf("%d %d %d %d\n", i * k, (i + 1) * k, (i + 2) * k, (i + 4) * k); 
        i += 6;
    }
    return 0;
}