#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) printf("1\n1");
    else if (n == 2) printf("1\n1");
    else if (n == 3) printf("2\n1 3");
    else if (n == 4) printf("4\n3 1 4 2");
    else {
        printf("%d\n", n);
        fto(i, 1, (n+1)/2) printf("%d ", i*2-1);
        fto(i, 1, n/2) printf("%d ", i*2);
    }
}