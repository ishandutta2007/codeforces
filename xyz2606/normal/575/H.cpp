#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N(2222222);
int modulo(1e9 + 7);
int inv[N];
int main() {
    int n;
    scanf("%d", &n);
    int val(n + 1), ans(0);
    inv[1] = 1;
    for(int i(2); i <= n + 10; i++) {
        inv[i] = (long long)(modulo + i - 1) / i * inv[i - modulo % i] % modulo;
    }
    for(int i(1); i <= n + 1; i++) {
        ans = (ans + val) % modulo;
        val = (long long)val * (i + n + 1) % modulo * inv[i + 1] % modulo; 
    }
    printf("%d\n", ans);
}