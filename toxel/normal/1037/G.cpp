#include <bits/stdc++.h>

const int N = 100010;
const int SIGMA = 26;

char s[N];
int right[N][SIGMA], left[N][SIGMA];
unsigned suf[N][SIGMA], right_ans[N][SIGMA], left_ans[N][SIGMA];
std::vector <int> vec[N];

unsigned calc(int l, int r){
    unsigned vis = 0;
    for (int i = 0; i < SIGMA; ++ i){
        int ll = right[l][i], rr = left[r][i];
        if (ll > rr){
            continue;
        }
        unsigned sum = right_ans[l][i] ^ left_ans[r][i] ^ suf[ll][i] ^ suf[rr][i];
        vis |= 1u << sum;
    }
    for (unsigned i = 0; i < 32; ++ i){
        if (!(vis >> i & 1u)){
            return i;
        }
    }
    return UINT_MAX;
}

int main(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    s[0] = s[n + 1] = '*';
    for (int j = 0; j < SIGMA; ++ j){
        int cur = 0;
        for (int i = 0; i <= n + 1; ++ i){
            if (s[i] == '*' || s[i] == j + 'a'){
                cur = i;
            }
            left[i][j] = cur;
        }
        for (int i = n + 1; i >= 0; -- i){
            if (s[i] == '*' || s[i] == j + 'a'){
                cur = i;
            }
            right[i][j] = cur;
        }
    }
    for (int i = 1; i <= n; ++ i){
        int j = i - 1;
        while (s[j] != s[i] && s[j] != '*'){
            -- j;
        }
        for (int k = j + 1; k < i; ++ k){
            vec[k].push_back(i - 1);
        }
    }
    for (int i = n; i >= 1; -- i){
        int j = i + 1;
        while (s[j] != s[i] && s[j] != '*'){
            ++ j;
        }
        unsigned last = 0;
        int ch = s[i] - 'a';
        for (int k = i + 1; k < j; ++ k){
            last = left_ans[k][ch] = calc(i + 1, k);
        }
        suf[i][ch] = suf[right[i + 1][ch]][ch] ^ last;
        for (auto u : vec[i]){
            right_ans[i][s[u + 1] - 'a'] = calc(i, u);
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int l, r;
        scanf("%d%d", &l, &r);
        unsigned sg = calc(l, r);
        puts(sg ? "Alice" : "Bob");
    }
    return 0;
}