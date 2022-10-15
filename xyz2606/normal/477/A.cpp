#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int modulo(1e9 + 7);
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    long long ans(0);
    for(int i(1); i < b; i++) {
        ans = ans + (long long)a * (a + 1) / 2 % modulo * i % modulo * b % modulo + (long long)a * i % modulo;
        ans = ans % modulo;
    }
    printf("%d\n", (int)ans);
}