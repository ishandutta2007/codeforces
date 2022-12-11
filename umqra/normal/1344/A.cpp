#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        set<int> remainders = {};
        for (int s = 0; s < n; s++) {
            int x;
            scanf("%d", &x);
            int rem = ((x + s) % n + n) % n;
            remainders.insert(rem); 
        }
        if (remainders.size() == n) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}