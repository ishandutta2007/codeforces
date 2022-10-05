#include<bits/stdc++.h>

const int N = 200010;

int a[N], b[N];

std::vector <int> getprime(int n){
    std::vector <int> ret;
    for (int i = 2; i * i <= n; ++ i){
        if (n % i == 0){
            ret.push_back(i);
            while (n % i == 0){
                n /= i;
            }
        }
    }
    if (n > 1){
        ret.push_back(n);
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &a[i], &b[i]);
    }
    std::vector <int> prime = getprime(a[0]);
    for (auto u : getprime(b[0])){
        prime.push_back(u);
    }
    for (auto u : prime){
        bool flag = true;
        for (int i = 0; i < n; ++ i){
            if (a[i] % u && b[i] % u){
                flag = false;
                break;
            }
        }
        if (flag){
            printf("%d\n", u);
            return 0;
        }
    }
    puts("-1");
    return 0;
}