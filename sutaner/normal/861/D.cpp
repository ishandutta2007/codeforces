#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 1000005
#define INF 2000000005
using namespace std;

char s[maxn];
int t1[maxn], t2[maxn];
int n, m;
int cnt[maxn];
int sa[maxn];
int rank[maxn];
int hei[maxn];
void build(){
    int *x = t1, *y = t2;
    m = 11;
    for (int i = 0; i < n; i++) cnt[x[i] = (s[i] - '0')]++;
    for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i > 0; i--) sa[--cnt[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1){
        int p = 0;
        for (int i = n - 1; i >= n - k; i--) y[p++] = i;
        for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < p; i++) cnt[x[y[i]]]++;
        for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for (int i = p - 1; i >= 0; i--) sa[--cnt[x[y[i]]]] = y[i];

        p = 0;
        swap(x, y);

        for (int i = 0; i < n; i++){
            x[sa[i]] = (!i || y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k]) ? p++ : p - 1;
        }
        m = p;
        if (m >= n) break;
    }

    for (int i = 0; i < n; i++) rank[sa[i]] = i;

    int h = 0;

    for (int i = 0; i < n; i++){
        if (h) h--;
        if (rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while (s[i + h] == s[j + h]) h++;
        hei[rank[i]] = h;
    }
}

int rec[maxn];
int ans[maxn];

int main(){
    char ch;
    scanf("%d%c", &n, &ch);
    for (int i = 0; i < n; i++) rec[i] = INF;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 9; j++){
            scanf("%c", &s[i * 10 + j]);
        }
        s[i * 10 + 9] = '9' + 1;
        scanf("%c", &ch);
    }

    if (n == 1){
        printf("%c", s[0]);
        return 0;
    }

    n = (n << 3) + (n << 1);
    build();
    for (int i = 0; i < n; i++){
        if (s[sa[i]] == '9' + 1) continue;
        
        int j = i;
        int now = sa[j] / 10;

        int pre = INF;
        int suf = INF;
        while (j && sa[j - 1] / 10 == now) pre = min(pre, hei[j--]);
        if (j) pre = min(pre, hei[j]);
        else pre = INF;

        j = i + 1;
        while (j < n && sa[j] / 10 == now) suf = min(suf, hei[j++]);
        if (j < n) suf = min(suf, hei[j]);
        else suf = INF;

        if (pre == INF) pre = suf;
        else if (suf != INF) pre = max(pre, suf);

        if (pre < rec[sa[i] / 10]) {
            if (sa[i] % 10 + pre < 9){
                rec[sa[i] / 10] = pre;
                ans[sa[i] / 10] = sa[i];
            }
        }
    }
    
    for (int i = 0; i < n / 10; i++){
        for (int j = ans[i]; j <= ans[i] + rec[i]; j++){
            printf("%c", s[j]);
        }
        printf("\n");
    }
    return 0;
}