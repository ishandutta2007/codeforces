

    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int t; scanf("%d", &t);
        while (t--) {
            int r, b, k; scanf("%d%d%d", &r, &b, &k);
            if (r > b) swap(r, b);
            int g = __gcd(r, b);
            r /= g, b /= g;
            if (r == b) {
                puts("OBEY");
                continue;
            }
            if (b > 1LL * r * k) {
                puts("REBEL");
                continue;
            }
            if (b == 1LL * r * k) {
                puts("OBEY");
                continue;
            }
            if (1LL * (k - 1) * r + 2 <= b) {
                puts("REBEL");
                continue;
            }
            puts("OBEY");
        }
        return 0;
    }