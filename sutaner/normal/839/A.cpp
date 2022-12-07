#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 1000005
using namespace std;
int n, m;

int main(){
    int k;
    scanf("%d%d", &n, &k);
    int now = 0;
    int ans = 0;
    int x;
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        now += x;
        ans += min(now, 8);
        now -= min(now, 8);
        if (ans >= k){
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}