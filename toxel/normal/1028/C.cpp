#include<bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;

int x1[N], Y1[N], x2[N], y2[N];
pii prex[N], prey[N], sufx[N], sufy[N];

void merge(pii &p1, pii p2){
    p1.first = std::max(p1.first, p2.first);
    p1.second = std::min(p1.second, p2.second);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d%d%d", &x1[i], &Y1[i], &x2[i], &y2[i]);
    }
    prex[0] = prey[0] = sufx[n + 1] = sufy[n + 1] = {INT_MIN, INT_MAX};
    for (int i = 1; i <= n; ++ i){
        prex[i] = prex[i - 1];
        merge(prex[i], {x1[i], x2[i]});
        prey[i] = prey[i - 1];
        merge(prey[i], {Y1[i], y2[i]});
    }
    for (int i = n; i >= 1; -- i){
        sufx[i] = sufx[i + 1];
        merge(sufx[i], {x1[i], x2[i]});
        sufy[i] = sufy[i + 1];
        merge(sufy[i], {Y1[i], y2[i]});
    }
    for (int i = 1; i <= n; ++ i){
        pii tmpx = prex[i - 1];
        merge(tmpx, sufx[i + 1]);
        pii tmpy = prey[i - 1];
        merge(tmpy, sufy[i + 1]);
        if (tmpx.first <= tmpx.second && tmpy.first <= tmpy.second){
            printf("%d %d\n", tmpx.first, tmpy.first);
            return 0;
        }
    }
    return 0;
}