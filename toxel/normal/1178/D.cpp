#include <bits/stdc++.h>

const int N = 10010;

std::vector <int> e[N];
std::vector <int> prime;
int min[N];

void solve(int n){
    int tot = n;
    for (int i = 1; i <= n; ++ i){
        int x = i + 1 == n + 1 ? 1 : i + 1;
        e[i].push_back(x);
        e[x].push_back(i);
    }
    int now = 1;
    while (min[tot] != tot){
        int x = now + 2;
        if (x > n){
            break;
        }
        e[now].push_back(x);
        e[x].push_back(now);
        ++ tot;
        now += now & 1 ? 1 : 3;
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++ i){
        for (auto u : e[i]){
            if (u > i){
                printf("%d %d\n", i, u);
            }
        }
    }
}

int main(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (i * u >= N){
                break;
            }
            min[i * u] = u;
            if (i % u == 0){
                break;
            }
        }
    }
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}