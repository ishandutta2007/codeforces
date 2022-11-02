#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int get(int n) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        ret += t;
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int s0 = get(n), s1 = get(n - 1), s2 = get(n - 2);
    printf("%d\n%d\n", s0 - s1, s1 - s2);
    return 0;
}