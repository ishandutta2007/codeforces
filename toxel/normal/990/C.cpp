#include<bits/stdc++.h>

const int N = 1000010;
typedef long long ll;

char ss[N], *s[N];
int len[N], dif[N];

int main(){
    int n;
    scanf("%d", &n);
    int nowscan = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%s", ss + nowscan);
        s[i] = ss + nowscan;
        len[i] = strlen(s[i]);
        nowscan += len[i] + 1;
    }
    std::map <int, int> Hash;
    for (int i = 0; i < n; ++ i){
        int left = 0, right = 0;
        bool flag = true;
        for (int j = 0; j < len[i]; ++ j){
            left += s[i][j] == '(';
            right += s[i][j] == ')';
            if (left < right){
                flag = false;
            }
        }
        dif[i] = left - right;
        if (flag){
            ++ Hash[dif[i]];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        if (dif[i] > 0) continue;
        int left = -dif[i], right = 0;
        bool flag = true;
        for (int j = 0; j < len[i]; ++ j){
            left += s[i][j] == '(';
            right += s[i][j] == ')';
            if (left < right){
                flag = false;
            }
        }
        if (flag){
            ans += Hash[-dif[i]];
        }
    }
    printf("%lld\n", ans);
    return 0;
}