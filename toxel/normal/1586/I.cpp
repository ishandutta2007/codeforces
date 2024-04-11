//
// Created by  on 2022/2/4.
//

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 2010;

char s[N][N];
int a[N][N];

void solve(){
    memset(a, -1, sizeof(a));
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++ i){
        std::cin >> s[i];
    }
    if (n % 2 == 1){
        std::cout << "NONE\n";
        return;
    }
    std::vector <int> result(n + 1, -1);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (s[i][j] != '.'){
                a[i][j] = s[i][j] == 'S' ? 0 : 1;
                int x = i, y = j;
                int reverse = 0;
                if ((x == 0 || x == n - 1) && (y == 0 || y == n - 1)){
                    if (x == n - 1){
                        x = 0;
                        y = n - 1 - y;
                    }
                }
                else if ((x + y) % 2 == 1){
                    if (x > y){
                        std::swap(x, y);
                    }
                    reverse = x & 1;
                    y -= x;
                    x = 0;
                }
                else{
                    if (x + y >= n){
                        y = 2 * (n - 1) - x - y;
                        reverse = (x & 1) ^ 1;
                    }
                    else{
                        y = x + y;
                        reverse = x & 1;
                    }
                    x = 0;
                }
                assert(x == 0);
                if (result[y] != -1 && result[y] != (a[i][j] ^ reverse)){
                    std::cout << "NONE\n";
                    return;
                }
                result[y] = a[i][j] ^ reverse;
            }
        }
    }
    bool multiple = false;
    for (int i = 0; i < n; i += 2){
        if (result[i] == -1 && result[i + 1] == -1){
            multiple = true;
            continue;
        }
        if (result[i] != -1 && result[i + 1] != -1 && result[i] != result[i + 1]){
            std::cout << "NONE\n";
            return;
        }
        if (result[i] == -1){
            result[i] = result[i + 1];
        }
        else{
            result[i + 1] = result[i];
        }
    }
    if (multiple){
        std::cout << "MULTIPLE\n";
        return;
    }
    std::cout << "UNIQUE\n";
    a[0][0] = a[n - 1][n - 1] = result[0];
    a[0][n - 1] = a[n - 1][0] = result[n - 1];
    for (int i = 1; i < n - 1; i += 2){
        for (int j = 0; j < n; ++ j){
            int x = j, y = i + j;
            if (y >= n){
                break;
            }
            a[x][y] = a[y][x] = result[i] ^ (j & 1);
        }
    }
    for (int i = 2; i < n - 1; i += 2){
        for (int j = 0; j < n; ++ j){
            int x = j, y = i - j;
            if (y < 0){
                continue;
            }
            a[x][y] = a[n - 1 - y][n - 1 - x] = result[i] ^ (j & 1);
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            std::cout << (a[i][j] ? 'G' : 'S');
        }
        std::cout << '\n';
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H