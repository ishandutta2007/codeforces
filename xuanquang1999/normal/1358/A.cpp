#include <bits/stdc++.h>

using namespace std;

int nTest, n, m;

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &m);
        printf("%d\n", (n*m+1) / 2);
    }
}