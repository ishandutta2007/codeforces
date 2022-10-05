#include<bits/stdc++.h>

const int N = 500010;
const int MAX = 1 << 19;
typedef std::pair <int, int> pii;

pii seg[MAX << 1];

void add(int sit, int value){
    seg[sit + MAX] = {value, sit};
    sit += MAX;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

pii query(int l, int r){
    pii ret = {INT_MIN, INT_MIN};
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::max(ret, seg[l ++]);
        if (r & 1) ret = std::max(ret, seg[-- r]);
    }
    return ret;
}

struct Query{
    int l, r, id;

    bool operator < (const Query &q)const{
        return l < q.l;
    }
};

int a[N];
std::deque <int> queue[N];
Query qq[N];
int ans[N];

void add(int i){
    if (queue[i].empty()){
        return;
    }
    if (queue[i].size() == 1){
        add(queue[i].front(), INT_MAX);
    }
    else{
        add(queue[i][0], queue[i][1]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        queue[a[i]].push_back(i);
    }
    for (int i = 0; i < MAX; ++ i){
        add(i, -1);
    }
    for (int i = 0; i < N; ++ i){
        add(i);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0, l, r; i < q; ++ i){
        scanf("%d%d", &l, &r);
        -- l, -- r;
        qq[i] = {l, r, i};
    }
    std::sort(qq, qq + q);
    for (int i = 0, j = 0; i < q; ++ i){
        while (j < n && j < qq[i].l){
            queue[a[j]].pop_front();
            add(a[j]);
            ++ j;
        }
        pii p = query(qq[i].l, qq[i].r);
        if (p.first > qq[i].r){
            ans[qq[i].id] = a[p.second];
        }
    }
    for (int i = 0; i < q; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}