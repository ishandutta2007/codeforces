#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define LL long long int
using namespace std;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 1;
    for (int i = 0; i < k; i++) {
        ans = ans * 10;
    }
    ans %= n;
    int d = gcd(ans, n);
    int t = n / d;
    printf("%d", t);
    for (int i = 0; i < k; i++) printf("0");
    return 0;
}