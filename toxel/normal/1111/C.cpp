#include<bits/stdc++.h>

typedef long long ll;

struct Seg{
    int value;
    Seg *child[2];

    Seg():value(0){child[0] = child[1] = nullptr;}
};

int getvalue(Seg *seg){
    return seg == nullptr ? 0 : seg -> value;
}

Seg *getchild(Seg *seg, int sit){
    return seg == nullptr ? nullptr : seg -> child[sit];
}

const int N = 100010;

Seg *segpool;
int segsz = 0;

Seg *newseg(){
    if (!segsz){
        segpool = new Seg[N];
        segsz += N;
    }
    return segpool + -- segsz;
}

int n, k, A, B;

ll dfs(Seg *root, int l, int r){
    if (getvalue(root) == 0){
        return A;
    }
    ll ret = 1ll * B * (r - l + 1) * getvalue(root);
    if (l < r){
        int mid = (l + r) >> 1;
        ret = std::min(ret, dfs(getchild(root, 0), l, mid) + dfs(getchild(root, 1), mid + 1, r));
    }
    return ret;
}

int main(){
    scanf("%d%d%d%d", &n, &k, &A, &B);
    Seg *root = newseg();
    for (int i = 0; i < k; ++ i){
        int x;
        scanf("%d", &x);
        -- x;
        Seg *p = root;
        for (int i = 0; i < n; ++ i){
            int bit = x >> (n - i - 1) & 1;
            if (getchild(p, bit) == nullptr){
                p -> child[bit] = newseg();
            }
            ++ p -> value;
            p = p -> child[bit];
        }
        ++ p -> value;
    }
    printf("%lld\n", dfs(root, 0, (1 << n) - 1));
}