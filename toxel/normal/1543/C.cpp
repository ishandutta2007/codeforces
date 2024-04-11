#include <bits/stdc++.h>

using db = double;
db eps = 1e-12;

db ans;

void dfs(db c, db m, db p, db v, int cnt, db prob){
    if (c >= eps){
        db diff = std::min(c, v);
        db m1, p1;
        if (m >= eps){
            m1 = m + 0.5 * diff;
            p1 = p + 0.5 * diff;
        }
        else{
            m1 = 0;
            p1 = p + diff;
        }
        dfs(c - diff, m1, p1, v, cnt + 1, prob * c);
    }
    if (m >= eps){
        db diff = std::min(m, v);
        db c1, p1;
        if (c >= eps){
            c1 = c + 0.5 * diff;
            p1 = p + 0.5 * diff;
        }
        else{
            c1 = 0;
            p1 = p + diff;
        }
        dfs(c1, m - diff, p1, v, cnt + 1, prob * m);
    }
    if (p >= eps){
        ans += prob * p * (cnt + 1);
    }
}

void solve(){
    db c, m, p, v;
    scanf("%lf%lf%lf%lf", &c, &m, &p, &v);
    ans = 0;
    dfs(c, m, p, v, 0, 1);
    printf("%.15f\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}