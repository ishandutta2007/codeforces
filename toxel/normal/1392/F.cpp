#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

template <typename T>
void read(T &n){
    n = 0;
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

ll h[N], hh[N];

void bf(int n){
    while (true){
        std::vector<int> vec;
        for (int i = 0; i < n - 1; ++ i){
            if (h[i] + 2 <= h[i + 1]){
                vec.emplace_back(i);
            }
        }
        if (vec.empty()){
            break;
        }
        for (auto u : vec){
            ++ h[u], -- h[u + 1];
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%lld%c", h[i], " \n"[i == n - 1]);
    }
}

void solve(int n, ll *h){
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        sum += h[i];
    }
    ll left = 0, right = 2e12;
    while (left < right){
        ll mid = (left + right) / 2;
        if ((mid + mid + n - 1) * n / 2 < sum){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    for (int i = 0; i < n; ++ i){
        h[i] = left + i;
    }
    ll tot = (left + left + n - 1) * n / 2;
    for (int i = n - (tot - sum); i < n; ++ i){
        -- h[i];
    }
}

int main(){
    srand((unsigned) time(nullptr));
    int n;
    read(n);
    // n = 10;
    for (int i = 0; i < n; ++ i){
        read(h[i]);
        // h[i] = i == 0 ? 0 : h[i - 1] + rand() % 3 + 1;
        hh[i] = h[i];
    }
    // bf(n);
    solve(n, hh);
    for (int i = 0; i < n; ++ i){
        printf("%lld%c", hh[i], " \n"[i == n - 1]);
    }
    /*for (int i = 0; i < n; ++ i){
        assert(h[i] == hh[i]);
    }*/
    return 0;
}