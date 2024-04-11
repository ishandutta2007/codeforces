#include<bits/stdc++.h>

const int N = 200010;
const int M = 30;
typedef long long ll;

char s[N];
int suf[N], sufcnt[N][M];
int sufcont[N];

int main(){
    int n, m;
    scanf("%d%d%s", &n, &m, s);
    for (int i = n - 1; i >= 0; -- i){
        suf[i] = suf[i + 1] + (s[i] != s[i + 1]);
        for (int j = 0; j < M; ++ j){
            sufcnt[i][j] = sufcnt[i + 1][j];
        }
        ++ sufcnt[i][s[i] - 'a'];
    }
    sufcont[n - 1] = 1;
    for (int i = n - 2; i >= 0; -- i){
        if (s[i] == s[i + 2]){
            if (s[i + 1] == s[i + 3]){
                sufcont[i] = sufcont[i + 2] + 2;
            }
            else{
                sufcont[i] = 3;
            }
        }
        else{
            sufcont[i] = 2;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        if (i == n - 1){
            ans += m - 1;
            continue;
        }
        if (s[i] == s[i + 1]){
            ans += (m - 1) * suf[i];
        }
        else{
            ans += (m - 2) * suf[i];
            ans += m * (n - i - 1) - (n - i - 2) + suf[i] - sufcont[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}