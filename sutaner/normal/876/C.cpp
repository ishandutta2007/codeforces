#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 1005
using namespace std;
int line[maxn];

int get_digit_sum(int x){
    int ans = 0;
    while (x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main(){
    /*freopen("C.in", "r", stdin):
    freopen("C.out", "w", stdout);*/
    int n;
    scanf("%d", &n);
    int ct = 0;
    for (int i = max(0, n - 100); i <= n; i++){
        if (i + get_digit_sum(i) == n) line[++ct] = i;
    }
    printf("%d\n", ct);
    for (int i = 1; i <= ct; i++){
        printf("%d\n", line[i]);
    }
    return 0;
}