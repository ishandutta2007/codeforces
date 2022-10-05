#include<bits/stdc++.h>

const int N = 300010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    std::multiset <int> small, big;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++ i){
        int x = INT_MIN, y = INT_MIN;
        if (!small.empty() && a[i] > *(small.begin())){
            x = a[i] - *(small.begin());
        }
        if (!big.empty() && a[i] > *(big.begin())){
            y = a[i] - *(big.begin());
        }
        if (x != INT_MIN && x >= y){
            ans += a[i] - *(small.begin());
            small.erase(small.begin());
            big.insert(a[i]);
        }
        else if (x < y){
            ans += a[i] - *(big.begin());
            small.insert(*(big.begin()));
            big.erase(big.begin());
            big.insert(a[i]);
        }
        else{
            small.insert(a[i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}