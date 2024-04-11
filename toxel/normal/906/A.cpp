#include<bits/stdc++.h>

const int N = 100010;

char s[N], w[N];

int main(){
    int q;
    scanf("%d", &q);
    int ans = 0;
    int pos = (1 << 26) - 1;
    while (q --){
        scanf("%s%s", s, w);
        int n = strlen(w);
        if (s[0] == '!'){
            if (__builtin_popcount(pos) == 1){
                ++ ans;
            }
            int tmp = 0;
            for (int i = 0; i < n; ++ i){
                tmp |= 1 << (w[i] - 'a');
            }
            pos = pos & tmp;
        }
        else if (s[0] == '.'){
            int tmp = 0;
            for (int i = 0; i < n; ++ i){
                tmp |= 1 << (w[i] - 'a');
            }
            pos = pos & ~tmp;
        }
        else{
            if (__builtin_popcount(pos) == 1){
                for (int i = 0; i < 26; ++ i){
                    if (pos >> i & 1){
                        if (i + 'a' != w[0]){
                            ++ ans;
                        }
                    }
                }
            }
            pos &= ~(1 << (w[0] - 'a'));
        }
    }
    printf("%d\n", ans);
    return 0;
}