#include<bits/stdc++.h>

typedef long long ll;
const int N = 100010;
typedef std::pair <int, int> pii;
typedef std::pair <double, int> pdi;

pii p[N];
pdi pa[N], pb[N];

inline double sqr(double n){return n * n;}

double dis(pii p1, pii p2){
    return std::sqrt(sqr(p1.first - p2.first) + sqr(p1.second - p2.second));
}

int main(){
    pii a, b, t;
    scanf("%d%d%d%d%d%d", &a.first, &a.second, &b.first, &b.second, &t.first, &t.second);
    int n;
    scanf("%d", &n);
    double ans = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &p[i].first, &p[i].second);
        double std = dis(p[i], t);
        pa[i] = {dis(a, p[i]) - std, i};
        pb[i] = {dis(b, p[i]) - std, i};
        ans += std * 2;
    }
    if (n == 1){
        double ans = std::min(dis(a, p[0]), dis(b, p[0])) + dis(p[0], t);
        printf("%.10lf\n", ans);
        return 0;
    }
    std::sort(pa, pa + n);
    std::sort(pb, pb + n);
    double ans1 = std::min(pa[0].first, pb[0].first) + ans;
    if (pa[0].second != pb[0].second){
        ans += pa[0].first + pb[0].first;
    }
    else{
        ans += std::min(pa[1].first + pb[0].first, pa[0].first + pb[1].first);
    }
    printf("%.10lf\n", std::min(ans1, ans));
    return 0;
}