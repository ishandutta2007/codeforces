#include <bits/stdc++.h>

const int N = 1000010;
typedef std::pair <int, int> pii;

int p[N];
int inv[N];
std::vector <pii> ans;

void print(int i, int j){
    if (i > j){
        std::swap(i, j);
    }
    ans.push_back({i + 1, j + 1});
    std::swap(p[i], p[j]);
    std::swap(inv[p[i]], inv[p[j]]);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &p[i]);
        -- p[i];
        inv[p[i]] = i;
    }
    int m = n >> 1;
    if (inv[0] < m){
        print(inv[0], n - 1);
        print(0, n - 1);
    }
    else{
        print(0, inv[0]);
    }
    for (int i = 1; i < m; ++ i){
        if (i == inv[i]){
            continue;
        }
        if (inv[i] < m){
            print(inv[i], n - 1);
            print(n - 1, i);
        }
        else if (inv[i] == n - 1) {
            print(inv[i], i);
        }
        else{
            int begin = inv[i];
            print(inv[i], 0);
            print(0, n - 1);
            print(n - 1, i);
            print(begin, 0);
        }
    }
    for (int i = m; i < n; ++ i){
        if (i == inv[i]){
            continue;
        }
        int begin = inv[i];
        print(inv[i], 0);
        print(inv[i], i);
        print(0, begin);
    }
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        printf("%d %d\n", u.first, u.second);
    }
    return 0;
}