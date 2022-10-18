#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

const int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int n, a[MAXN], ans[MAXN];

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);

        for(int i = 1; i <= n; ++i)
            ans[i] = -1;
        
        int id = 1;
        for(int p = 0; p < 11; ++p) {
            bool used = false;
            for(int i = 1; i <= n; ++i) {
                if (ans[i] == -1 && a[i] % primes[p] == 0) {
                    used = true;
                    ans[i] = id;
                }
            }
            if (used)
                ++id;            
        }

        printf("%d\n", id - 1);
        for(int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
        puts("");
    }

    return 0;
}