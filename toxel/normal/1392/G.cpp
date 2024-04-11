#include <bits/stdc++.h>

using pii = std::pair <int, int>;

template <typename T>
void read(T &n){
    n = 0;
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

const int N = 2000010;

char s[N], t[N];
int a[N], b[N];
int seqa[N], seqb[N];
int perm[N];
int bitcnt[N];
int lefta[N], rightb[N];

int parse(char *s, int k){
    int ret = 0;
    for (int i = 0; i < k; ++ i){
        ret = ret << 1 | (s[perm[i]] - '0');
    }
    return ret;
}

int main(){
    for (int i = 1; i < N; ++ i){
        bitcnt[i] = bitcnt[i >> 1] + (i & 1);
    }
    int n, m, k;
    read(n), read(m), read(k);
    scanf("%s%s", s, t);
    for (int i = 0; i < n; ++ i){
        read(a[i]), read(b[i]);
        -- a[i], -- b[i];
    }
    for (int i = 0; i < k; ++ i){
        perm[i] = i;
    }
    for (int i = n; i >= 0; -- i){
        seqa[i] = parse(s, k);
        seqb[i] = parse(t, k);
        if (!i){
            continue;
        }
        int pos1 = 0, pos2 = 0;
        for (int j = 0; j < k; ++ j){
            if (perm[j] == a[i - 1]){
                pos1 = j;
            }
            if (perm[j] == b[i - 1]){
                pos2 = j;
            }
        }
        std::swap(perm[pos1], perm[pos2]);
    }
    const int INF = 0x3f3f'3f3f;
    memset(lefta, 0x3f, sizeof(lefta));
    for (int i = 0; i <= n; ++ i){
        lefta[seqa[i]] = std::min(lefta[seqa[i]], i);
        rightb[seqb[i]] = std::max(rightb[seqb[i]], i);
    }
    for (int i = 0; i < k; ++ i){
        for (int j = 0; j < 1 << k; ++ j){
            if (!(j >> i & 1)){
                lefta[j] = std::min(lefta[j], lefta[j ^ 1 << i]);
                rightb[j] = std::max(rightb[j], rightb[j ^ 1 << i]);
            }
        }
    }
    int ans = -1;
    int x = k;
    for (int i = 0; i < k; ++ i){
        if (s[i] == '1'){
            -- x;
        }
        if (t[i] == '1'){
            -- x;
        }
    }
    int l = -1, r = -1;
    for (int i = 0; i < 1 << k; ++ i){
        if (rightb[i] - lefta[i] >= m){
            int value = bitcnt[i] * 2 + x;
            if (value > ans){
                ans = value;
                l = lefta[i] + 1, r = rightb[i];
            }
        }
    }
    printf("%d\n%d %d\n", ans, l, r);
    return 0;
}