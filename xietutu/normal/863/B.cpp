#include <bits/stdc++.h>
using namespace std;
int n, w[110];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; ++i)
        scanf("%d", w + i);
    sort(w + 1, w + n * 2 + 1);
    
    int ans = INT_MAX;
    for (int i = 1; i <= n * 2; ++i)
        for (int j = i + 1; j <= n * 2; ++j) {
            int last = 0, s = 0 ;
            for (int k = 1; k <= n * 2; ++k)
                if (k != i && k != j) {
                    if (!last) last = k;
                    else {
                        s += w[k] - w[last];
                        last = 0;
                    }
                } 
            ans = min(ans, s);            
        }
    printf("%d\n", ans);
}