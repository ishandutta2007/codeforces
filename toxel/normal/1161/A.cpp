#include <bits/stdc++.h>

const int N = 100010;

std::vector <int> vec[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, x; i < k; ++ i){
        scanf("%d", &x);
        vec[x].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (vec[i].empty()){
            ans += i == 1 || i == n ? 2 : 3;
            continue;
        }
        if (i > 1){
            if (vec[i - 1].empty() || vec[i - 1].back() < vec[i].front()){
                ++ ans;
            }
        }
        if (i < n){
            if (vec[i + 1].empty() || vec[i + 1].back() < vec[i].front()){
                ++ ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}