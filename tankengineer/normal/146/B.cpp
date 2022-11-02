#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int mask(int n) {
    int ret = 0, mul = 1;
    while (n) {
        int t = n % 10;
        n /= 10;
        if (t == 4 || t == 7) {
            ret += mul * t;
            mul *= 10;
        }
    }
    return ret;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    ++a;
    while (mask(a) != b) {
        ++a;
    }
    printf("%d\n", a);
    return 0;
}