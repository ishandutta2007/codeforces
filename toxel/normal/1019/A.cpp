#include<bits/stdc++.h>

const int N = 3010;
typedef long long ll;

int n, m;
int p[N], c[N];
std::vector <int> vec[N];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &p[i], &c[i]);
        vec[p[i]].push_back(c[i]);
    }
    for (int i = 2; i <= m; ++ i){
        std::sort(vec[i].begin(), vec[i].end());
    }
    ll min = LLONG_MAX;
    for (int i = 1; i <= n; ++ i){
        ll sum = 0;
        std::multiset <int> set;
        for (int j = 2; j <= m; ++ j){
            if (vec[j].size() >= i){
                for (int k = 0; k < vec[j].size() - i + 1; ++ k){
                    sum += vec[j][k];
                }
                for (int k = vec[j].size() - i + 1; k < vec[j].size(); ++ k){
                    set.insert(vec[j][k]);
                }
            }
            else{
                for (auto u : vec[j]){
                    set.insert(u);
                }
            }
            while (set.size() > n - i){
                sum += *(set.begin());
                set.erase(set.begin());
            }
        }
        min = std::min(min, sum);
    }
    printf("%lld\n", min);
    return 0;
}