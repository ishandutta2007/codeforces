#include<bits/stdc++.h>

struct zzh{
    int a, b, c, d;
};

const int N = 310;
const int M = 1000010;

std::string s[N][N], t[N][N];
std::deque <char> queue[N][N];
int cnt[N][2];
char str[M];
std::vector <zzh> ans;

void print(int x1, int y1, int x2, int y2){
    ans.push_back({x1 + 1, y1 + 1, x2 + 1, y2 + 1});
    queue[x2][y2].push_front(queue[x1][y1].back());
    queue[x1][y1].pop_back();
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%s", str);
            s[i][j] = str;
            for (char *p = str; *p != '\0'; ++ p){
                queue[i][j].push_back(*p);
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%s", str);
            t[i][j] = str;
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 1; j < m - 1; ++ j){
            for (int k = s[i][j].size() - 1; k >= 0; -- k){
                print(i, j, i, s[i][j][k] == '0' ? 0 : m - 1);
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = s[i][0].size() - 1; j >= 0; -- j){
            if (s[i][0][j] == '0'){
                print(i, 0, (i + 1) % n, 0);
            }
            else{
                print(i, 0, i, m - 1);
            }
        }
        for (int j = s[i][m - 1].size() - 1; j >= 0; -- j){
            if (s[i][m - 1][j] == '1'){
                print(i, m - 1, (i + 1) % n, m - 1);
            }
            else{
                print(i, m - 1, i, 0);
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            for (auto u : t[i][j]){
                ++ cnt[i][u - '0'];
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        while (queue[i][0].size() > cnt[(i + 1) % n][0]){
            for (int j = 0; j < n; ++ j){
                if (queue[j][0].size() < cnt[(j + 1) % n][0]){
                    print(i, 0, j, 0);
                    break;
                }
            }
        }
        while (queue[i][m - 1].size() > cnt[i][1]){
            for (int j = 0; j < n; ++ j){
                if (queue[j][m - 1].size() < cnt[j][1]){
                    print(i, m - 1, j, m - 1);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = m - 1; j >= 0; -- j){
            for (int k = t[i][j].size() - 1; k >= 0; -- k){
                if (t[i][j][k] == '0'){
                    print((i - 1 + n) % n, 0, i, 0);
                }
                else{
                    print(i, m - 1, i, 0);
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = m - 1; j >= 1; -- j){
            for (auto u : t[i][j]){
                print(i, 0, i, j);
            }
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        printf("%d %d %d %d\n", u.a, u.b, u.c, u.d);
    }
    return 0;
}