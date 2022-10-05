#include <bits/stdc++.h>

const int N = 200010;

int a[N], b[N];
std::vector <int> vec[N];

bool check(int num, int n){
    if (num == n){
        return false;
    }
    for (int i = 0; i < N; ++ i){
        if (vec[i].empty()){
            continue;
        }
        if (n % 2 == 0 && i == n / 2){
            continue;
        }
        int pos = -1;
        for (int j = 0; j < vec[i].size(); ++ j){
            if ((vec[i][0] + num) % n == vec[i][j]){
                pos = j;
                break;
            }
        }
        if (pos == -1){
            return false;
        }
        for (int j = 0; j < vec[i].size(); ++ j){
            if ((vec[i][j] + num) % n != vec[i][(j + pos) % vec[i].size()]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &a[i], &b[i]);
        int diff = (b[i] - a[i] + n) % n;
        if (diff > n / 2){
            std::swap(a[i], b[i]);
            diff = n - diff;
        }
        vec[diff].push_back(a[i] - 1);
        if (n % 2 == 0 && diff == n / 2){
            vec[diff].push_back(b[i] - 1);
        }
    }
    for (int i = 0; i < N; ++ i){
        std::sort(vec[i].begin(), vec[i].end());
    }
    for (int i = 1; i * i <= n; ++ i){
        if (n % i == 0){
            if (check(i, n)){
                puts("Yes");
                return 0;
            }
            if (check(n / i, n)){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}