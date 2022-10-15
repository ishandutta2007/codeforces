#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long gcd(const long long & a, const long long & b) {
    return b ? gcd(b, a % b) : a;
}
int main() {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    if(gcd(a, b) > 1) {
        printf("Impossible\n");
        return 0;
    }
    while(a != 1 || b != 1) {
        if(a > b) {
            printf("%I64dA", (a - 1) / b);
            a -= (a - 1) / b * b;
        }else {
            printf("%I64dB", (b - 1) / a);
            b -= (b - 1) / a * a;
        }
    }
    printf("\n");
}