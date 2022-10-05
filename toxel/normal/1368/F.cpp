#include <bits/stdc++.h>

const int N = 1010;

int n;
bool vis[N], has[N];
int cnt = 0;

void ask(const std::vector <int> &vec){
    int k = vec.size();
    printf("%d", k);
    for (int i = 0; i < k; ++ i){
        printf(" %d", vec[i] + 1);
        vis[vec[i]] = true;
        ++ cnt;
    }
    puts("");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    -- x;
    for (int j = x; j < x + k; ++ j){
        int y = j % n;
        if (vis[y]){
            vis[y] = false;
            -- cnt;
        }
    }
}

int main(){
    scanf("%d", &n);
    if (n == 1){
        puts("0");
        return 0;
    }
    int max = -1, pos = 0;
    for (int i = 1; i <= n; ++ i){
        if (n - i < i){
            break;
        }
        int value = n - i - (n - i + i - 1) / i;
        if (value > max){
            max = value;
            pos = i;
        }
    }
    int bigcnt = (n - pos) % pos;
    int smallcnt = pos - bigcnt;
    int cur = 0;
    for (int i = 0; i < smallcnt; ++ i){
        for (int j = cur; j < cur + (n - pos) / pos; ++ j){
            has[j] = true;
        }
        cur += (n - pos) / pos + 1;
    }
    for (int i = 0; i < bigcnt; ++ i){
        for (int j = cur; j < cur + (n - pos) / pos + 1; ++ j){
            has[j] = true;
        }
        cur += (n - pos) / pos + 2;
    }
    while (cnt < max){
        std::vector<int> vec;
        for (int i = 0; i < n; ++ i){
            if (has[i] && !vis[i]){
                vec.emplace_back(i);
            }
        }
        ask(vec);
    }
    puts("0");
    return 0;
}