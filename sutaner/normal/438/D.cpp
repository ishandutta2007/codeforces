#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 1000005
#define LL long long int
using namespace std;
LL maxnum[maxn << 1];
LL sum[maxn << 1];
LL line[maxn];

LL qx, qy, qd;

void init(LL l, LL r, LL o){
    if (l == r){
        maxnum[o] = line[l];
        sum[o] = line[l];
        return;
    }
    LL mid = ((r - l) >> 1) + l;
    init(l, mid, o << 1);
    init(mid + 1, r, o << 1 | 1);
    maxnum[o] = max(maxnum[o << 1], maxnum[o << 1 | 1]);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void modify(LL l, LL r, LL o){
    if (l == r){
        sum[o] = qd;
        maxnum[o] = qd;
        return;
    }
    LL mid = ((r - l) >> 1) + l;
    if (qx <= mid) modify(l, mid, o << 1);
    else modify(mid + 1, r, o << 1 | 1);
    maxnum[o] = max(maxnum[o << 1], maxnum[o << 1 | 1]);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void modulo(LL l, LL r, LL o){
    if (maxnum[o] < qd) return;
    if (l == r){
        sum[o] %= qd;
        maxnum[o] %= qd;
        return;
    }
    LL mid = ((r - l) >> 1) + l;
    if (qx <= mid) modulo(l, mid, o << 1);
    if (qy > mid) modulo(mid + 1, r, o << 1 | 1);
    maxnum[o] = max(maxnum[o << 1], maxnum[o << 1 | 1]);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

LL get(LL l, LL r, LL o){
    if (qx <= l && r <= qy){
        return sum[o];
    }
    LL mid = ((r - l) >> 1) + l;
    LL ans = 0;
    if (qx <= mid) ans += get(l, mid, o << 1);
    if (qy > mid) ans += get(mid + 1, r, o << 1 | 1);
    return ans; 
}

int main(){
    /*freopen("child.in", "r", stdin);
    freopen("child.out", "w", stdout);*/
    LL n, m, op; 
    scanf(" %I64d %I64d", &n, &m);
    for (LL i = 1; i <= n;i++){
        scanf(" %I64d", &line[i]);
    }
    init(1, n, 1);
    for (LL i = 0; i < m; i++){
        scanf(" %I64d", &op);
        if (op == 1){
            scanf("%I64d %I64d", &qx, &qy);
            printf("%I64d\n", get(1, n, 1));
        }
        else if (op == 2){
            scanf(" %I64d %I64d %I64d", &qx, &qy, &qd);
            modulo(1, n, 1);
        }
        else{
            scanf(" %I64d %I64d", &qx, &qd);
            modify(1, n, 1);
        }
    }
    return 0;
}