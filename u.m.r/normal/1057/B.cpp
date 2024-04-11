#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int a[MAXN];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1, sm = a[i]; j <= n + 1; j++){
            if (sm > 100 * (j - i))
                ans = max(ans, j - i);
            sm += a[j];
        }
    }
    printf("%d\n", ans);
    return 0;
}