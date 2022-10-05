#include <bits/stdc++.h>

const int N = 1000010;
const int MAX = 1 << 19;
using ll = long long;

char s[N];
int sa[N], id[N], rk[N], oldrk[N << 1], tmp[N], cnt[N], height[N];

void get_sa(char *s, int *sa){
    int n = strlen(s + 1), m = 300;
    for (int i = 1; i <= n; ++ i) ++ cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; -- i) sa[cnt[s[i]] --] = i;
    auto equal = [&](int x, int y, int w){return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];};
    for (int w = 1, p; w < n; w <<= 1, m = p){
        p = 0;
        for (int i = n; i > n - w; -- i) id[++ p] = i;
        for (int i = 1; i <= n; ++ i){
            if (sa[i] > w) id[++ p] = sa[i] - w;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++ i) ++ cnt[tmp[i] = rk[id[i]]];
        for (int i = 1; i <= m; ++ i) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; -- i) sa[cnt[tmp[i]] --] = id[i];
        memcpy(oldrk, rk, sizeof(rk));
        p = 0;
        for (int i = 1; i <= n; ++ i){
            rk[sa[i]] = equal(sa[i - 1], sa[i], w) ? p : ++ p;
        }
    }
    for (int i = 1, p = 0; i <= n; ++ i){
        if (p) -- p;
        while (s[i + p] == s[sa[rk[i] - 1] + p]) ++ p;
        height[rk[i]] = p;
    }
}

char *p[N];
int begin[N], len[N], type[N];
int right_k[N];
std::vector<int> vec[N];
int seg[MAX << 1];

int query1(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return -1;
    }
    if (seg[sit] >= value){
        return -1;
    }
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    int ret = query1(sit << 1, l, mid, ql, qr, value);
    if (ret != -1){
        return ret;
    }
    return query1(sit << 1 | 1, mid + 1, r, ql, qr, value);
}

int query2(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return -1;
    }
    if (seg[sit] >= value){
        return -1;
    }
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    int ret = query2(sit << 1 | 1, mid + 1, r, ql, qr, value);
    if (ret != -1){
        return ret;
    }
    return query2(sit << 1, l, mid, ql, qr, value);
}

int query1(int l, int r, int value){
    if (l > r){
        return -1;
    }
    return query1(1, 0, MAX - 1, l, r, value);
}

int query2(int l, int r, int value){
    if (l > r){
        return -1;
    }
    return query2(1, 0, MAX - 1, l, r, value);
}

bool check(int pos, int l, int r, int tot, int k){
    int x = rk[begin[pos] + l - 1];
    int right = query1(x + 1, tot, r - l + 1);
    right = right == -1 ? tot : right - 1;
    int left = query2(2, x, r - l + 1);
    left = left == -1 ? 1 : left;
    return right_k[left] <= right;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    char *cur_p = s + 1;
    for (int i = 1; i <= n; ++ i){
        p[i] = cur_p;
        begin[i] = cur_p - s;
        scanf("%s", cur_p);
        len[i] = strlen(cur_p);
        cur_p += len[i];
        *cur_p = '#';
        ++ cur_p;
    }
    get_sa(s, sa);
    for (int i = 1; i <= n; ++ i){
        for (int j = begin[i]; j < begin[i] + len[i]; ++ j){
            type[rk[j]] = i;
        }
    }
    int tot = strlen(s + 1);
    int type_cnt = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1, j = 0; i <= tot; ++ i){
        while (j <= tot && type_cnt < k){
            ++ j;
            if (j > tot){
                break;
            }
            if (type[j] > 0){
                if (!cnt[type[j]]){
                    ++ type_cnt;
                }
                ++ cnt[type[j]];
            }
        }
        right_k[i] = j;
        if (type[i] == 0){
            continue;
        }
        if (cnt[type[i]] == 1){
            -- type_cnt;
        }
        -- cnt[type[i]];
    }
    for (int i = 2; i <= tot; ++ i){
        seg[i + MAX] = height[i];
    }
    for (int i = MAX - 1; i; -- i){
        seg[i] = std::min(seg[i << 1], seg[i << 1 | 1]);
    }
    for (int i = 1; i <= n; ++ i){
        ll ans = 0;
        for (int l = 1, r = 1; l <= len[i]; ++ l, r = std::max(l, r)){
            while (r <= len[i] && check(i, l, r, tot, k)){
                ++ r;
            }
            ans += r - l;
        }
        printf("%lld%c", ans, " \n"[i == n]);
    }
    return 0;
}