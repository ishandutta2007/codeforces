#include <bits/stdc++.h>

using namespace std;

const int perm[6] = {4, 1, 3, 2, 0, 5};

int main() {
    int x;
    scanf("%d", &x);

    int ans = 0;
    for(int i = 0; i < 6; ++i)
        if ((x>>i)&1)
            ans += 1 << perm[i];

    printf("%d\n", ans);
    
    return 0;
}