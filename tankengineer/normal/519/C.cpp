#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int a, b, ans;
    scanf("%d%d", &a, &b);
    ans = min((a + b) / 3, min(a, b));
    printf("%d\n", ans);
    return 0;
}