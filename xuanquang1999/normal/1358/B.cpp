#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int nTest, n, a[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        sort(a, a+n);

        int ans = 1;
        for(int i = 0; i < n; ++i) 
            if (a[i] <= i+1)
                ans = i+2;
        
        printf("%d\n", ans);
    }
}