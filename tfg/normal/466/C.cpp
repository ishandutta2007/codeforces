#include <iostream>
#include <cstdio>

long long a[500500];

int main() {
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        a[i] += a[i - 1];
    }
    if(a[n] % 3 != 0) {
        std::cout << 0 << '\n';
        return 0;
    }
    long long f = 0, s = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] == 2 * a[n] / 3) {
            s += f;
        }
        if(a[i] == a[n] / 3) {
            f++;
        }
        
    }
    std::cout << s << '\n';
}