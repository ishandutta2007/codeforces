#include <bits/stdc++.h>

#define MAXN (1000001)
#define ll long long

struct node{
    int l, r, id;
}query[MAXN];
int BLOCKSIZE;
int n, m;
int c[MAXN], cnt[MAXN], bel[MAXN];
ll sum = 0;

bool cmp(const node &A, const node &B){
    return bel[A.l] == bel[B.l] ? A.r < B.r : A.l < B.l;
}

int main(){
    scanf("%d", &m);
    BLOCKSIZE = (int)(ceil(sqrt(MAXN)));
    for(int i = 0; i < MAXN; ++ i){
        bel[i] = i / BLOCKSIZE;
    }
    for(int i = 1; i <= m; ++ i){
        int l, r;
        scanf("%d%d", &l, &r);
        query[i] = {l, r, i};
    }
    std::sort(query + 1, m + query + 1, cmp);

    ll sum = 0;
    for (int i = 1; i < m; ++ i){
        sum += std::abs(query[i + 1].l - query[i].l) + std::abs(query[i + 1].r - query[i].r);
    }
    if (sum > 2.49999e9){
        for (int i = 1; i <= m; ++ i){
            std::swap(query[i].l, query[i].r);
        }
        std::sort(query + 1, m + query + 1, cmp);
        for (int i = 1; i <= m; ++ i){
            std::swap(query[i].l, query[i].r);
        }
    }

    for(int i = 1; i <= m; ++ i){
        printf("%d%c", query[i].id, " \n"[i == m]);
    }
    return 0;
}