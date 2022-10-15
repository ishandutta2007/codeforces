#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int inch = n / 3;
    int rest = n % 3;
    if (rest == 2) inch++;
    printf("%d %d\n",inch / 12, inch % 12);
    return 0;
}