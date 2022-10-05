#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;
typedef std::pair <int, int> pii;

int a[N];
pii p[N];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        p[i] = {a[i], i};
    }
    std::sort(p, p + n, std::greater <pii>());
    std::vector <int> index;
    ll ans = 0;
    for (int i = 0; i < k * m; ++ i){
        ans += p[i].first;
        index.push_back(p[i].second);
    }
    std::sort(index.begin(), index.end());
    printf("%lld\n", ans);
    for (int i = 0; i < k - 1; ++ i){
        printf("%d%c", index[(i + 1) * m - 1] + 1, " \n"[i == k - 2]);
    }
    return 0;
}