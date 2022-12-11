#include<bits/stdc++.h>

const int N = 1000010;
const int moder = 998244353;

namespace kmp {
    int nxt[N], ex[N];

    void getnext(char *t) {
        int k = 0;
        int n = strlen(t);
        nxt[0] = n;
        while (k < n - 1 && t[k] == t[k + 1]) ++ k;
        nxt[1] = k;
        k = 1;
        for (int i = 2; i < n; ++ i) {
            int p = k + nxt[k] - 1, l = nxt[i - k];
            if (i + l - 1 >= p) {
                int j = (p - i + 1) > 0 ? p - i + 1 : 0;
                while (i + j < n && t[i + j] == t[j]) ++ j;
                nxt[i] = j;
                k = i;
            } else {
                nxt[i] = l;
            }
        }
    }

    void getex(char *s, char *t) {
        int k = 0;
        getnext(t);
        int sn = strlen(s);
        int tn = strlen(t);
        int n = sn < tn ? sn : tn;
        while (k < n && s[k] == t[k]) ++ k;
        ex[0] = k;
        k = 0;
        for (int i = 1; i < sn; ++ i) {
            int p = k + ex[k] - 1, l = nxt[i - k];
            if (i + l - 1 >= p) {
                int j = (p - i + 1) > 0 ? p - i + 1 : 0;
                while (i + j < sn && j < tn && s[i + j] == t[j]) ++ j;
                ex[i] = j;
                k = i;
            }
            else{
                ex[i] = l;
            }
        }
    }
}

char a[N], l[N], r[N];
int c[N], dp[N];
int ex1[N], ex2[N];

void add(int sit, int value){
    for (++ sit; sit < N; sit += sit & -sit){
        c[sit] += value;
        c[sit] -= c[sit] >= moder ? moder : 0;
    }
}

int query(int sit){
    int ret = 0;
    for (++ sit; sit; sit -= sit & -sit){
        ret += c[sit];
        ret -= ret >= moder ? moder : 0;
    }
    return ret;
}

int main(){
    scanf("%s%s%s", a, l, r);
    int n = strlen(a);
    int lenl = strlen(l);
    int lenr = strlen(r);
    kmp::getex(a, l);
    memcpy(ex1, kmp::ex, sizeof(ex1));
    kmp::getex(a, r);
    memcpy(ex2, kmp::ex, sizeof(ex2));
    dp[0] = 1;
    add(0, 1);
    for (int i = 1; i <= n; ++ i){
        int left = i - lenr, right = i - lenl;
        if (right < 0){
            continue;
        }
        if (ex1[right] < lenl){
            char ch = a[right + ex1[right]];
            if (ch < l[ex1[right]]){
                -- right;
            }
        }
        if (left >= 0){
            if (ex2[left] < lenr){
                char ch = a[left + ex2[left]];
                if (ch > r[ex2[left]]){
                    ++ left;
                }
            }
        }
        else{
            left = 0;
        }
        if (left <= right){
            dp[i] = query(right) - query(left - 1);
        }
        dp[i] += dp[i] < 0 ? moder : 0;
        if (a[i - 1] == '0' && lenl == 1 && l[0] == '0'){
            dp[i] += dp[i - 1];
            dp[i] -= dp[i] >= moder ? moder : 0;
        }
        if (a[i] != '0'){
            add(i, dp[i]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}