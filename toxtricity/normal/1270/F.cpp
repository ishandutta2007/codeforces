#include <bits/stdc++.h>

const int N = 200010;
const int BLOCK = 107;
//const int BLOCK = 1;
const int BLOCK1 = N / BLOCK + 5;
using ll = long long;

char s[N];
int pre[N];
int next[N], a[N];

int main(){
    //printf("%.15f\n", 200000 / std::sqrt(200000 * std::log2(200000)));
    scanf("%s", s + 1);
    /*sit begin = clock();
    for (int i = 1; i <= 200000; ++ i){
        s[i] = '1';
    }*/
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (s[i] == '1');
    }
    next[n + 1] = n + 1;
    for (int i = n; i >= 1; -- i){
        if (s[i] == '1'){
            next[i] = i;
        }
        else{
            next[i] = next[i + 1];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= BLOCK; ++ i){
        a[0] = 0;
        for (int j = 1; j <= n; ++ j){
            a[j] = j - i * pre[j];
        }
        std::sort(a, a + n + 1);
        int prev = -1;
        for (int j = 0; j <= n; ++ j){
            if (j == n || a[j] != a[j + 1]){
                int x = j - prev;
                ans += 1ll * x * (x - 1) / 2;
                prev = j;
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        int cnt1 = 1, pos = next[i];
        while (cnt1 < BLOCK1 && pos <= n){
            int next_pos = next[pos + 1];
            int left = pos - i, right = next_pos - i;
            ans += std::max(0, right / cnt1 - BLOCK) - std::max(0, left / cnt1 - BLOCK);
            pos = next_pos;
            ++ cnt1;
        }
    }
    printf("%lld\n", ans);
    //printf("%.15f\n", 1.0 * (clock() - begin) / CLOCKS_PER_SEC);
    return 0;
}