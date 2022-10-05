#include<bits/stdc++.h>

typedef long long ll;

ll calc(int n, int c){
    return 1ll * (1 + n - c + 1) * (n / c) / 2;
}

int main(){
    int n;
    scanf("%d", &n);
    std::vector <ll> vec;
    for (int i = 1; i * i <= n; ++ i){
        if (n % i == 0){
            vec.push_back(calc(n, i));
            if (i * i != n){
                vec.push_back(calc(n, n / i));
            }
        }
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0, sz = vec.size(); i < sz; ++ i){
        printf("%lld%c", vec[i], " \n"[i == sz - 1]);
    }
    return 0;
}