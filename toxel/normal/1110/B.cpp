#include<bits/stdc++.h>

const int N = 100010;

int b[N];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    std::vector <int> vec;
    for (int i = 0; i < n - 1; ++ i){
        vec.push_back(b[i + 1] - b[i]);
    }
    std::sort(vec.begin(), vec.end());
    int ans = k;
    for (int i = 0; i < n - k; ++ i){
        ans += vec[i];
    }
    printf("%d\n", ans);
    return 0;
}