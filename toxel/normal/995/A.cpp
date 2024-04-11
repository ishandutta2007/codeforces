#include<bits/stdc++.h>

const int N = 60;
const int M = 4;
typedef std::pair <int, int> pii;

struct answer{
    int r, x, y;

    void print(){
        printf("%d %d %d\n", r, x + 1, y + 1);
    }
};

std::vector <answer> ans;

int a[M][N];
bool move[N << 1];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < M; ++ i){
        for (int j = 0; j < n; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    int flag = false;
    for (int i = 0; i < n; ++ i){
        if (!a[1][i] || a[1][i] == a[0][i]){
            flag = true;
        }
        if (!a[2][i] || a[2][i] == a[3][i]){
            flag = true;
        }
    }
    if (!flag){
        puts("-1");
        return 0;
    }
    while (true){
        for (int i = 0; i < n; ++ i){
            if (a[1][i] && a[1][i] == a[0][i]){
                ans.push_back({a[1][i], 0, i});
                a[1][i] = 0;
            }
            if (a[2][i] && a[2][i] == a[3][i]){
                ans.push_back({a[2][i], 3, i});
                a[2][i] = 0;
            }
        }
        int cnt = 0;
        memset(move, false, sizeof(move));
        for (int i = 1; i <= 2; ++ i){
            for (int j = 0; j < n; ++ j){
                if (a[i][j]){
                    move[a[i][j]] = true;
                    ++ cnt;
                }
            }
        }
        if (!cnt){
            break;
        }
        while (cnt){
            for (int i = 1; i < n; ++ i){
                if (!move[a[1][i]]) continue;
                if (a[1][i - 1]) continue;
                ans.push_back({a[1][i], 1, i - 1});
                move[a[1][i]] = false;
                -- cnt;
                std::swap(a[1][i], a[1][i - 1]);
            }
            if (move[a[2][n - 1]] && !a[1][n - 1]){
                ans.push_back({a[2][n - 1], 1, n - 1});
                move[a[2][n - 1]] = false;
                -- cnt;
                std::swap(a[2][n - 1], a[1][n - 1]);
            }
            for (int i = n - 2; i >= 0; -- i){
                if (!move[a[2][i]]) continue;
                if (a[2][i + 1]) continue;
                ans.push_back({a[2][i], 2, i + 1});
                move[a[2][i]] = false;
                -- cnt;
                std::swap(a[2][i], a[2][i + 1]);
            }
            if (move[a[1][0]] && !a[2][0]){
                ans.push_back({a[1][0], 2, 0});
                move[a[1][0]] = false;
                -- cnt;
                std::swap(a[1][0], a[2][0]);
            }
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        u.print();
    }
    return 0;
}