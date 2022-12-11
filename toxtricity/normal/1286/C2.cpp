#include <bits/stdc++.h>

const int N = 210;

char tmp[N];
int cnt[N][N], cnt1[N];
char input[N];
int tot;

struct Event{
    int pos1, pos2;
    char ch1, ch2;
};

std::vector <Event> vec;

std::string ask(int l, int r){
    memset(cnt, 0, sizeof(cnt));
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int n = r - l + 1;
    for (int i = 0; i < n * (n + 1) / 2; ++ i){
        scanf("%s", tmp);
        int len = strlen(tmp);
        for (int j = 0; j < len; ++ j){
            ++ cnt[len][tmp[j]];
        }
    }
    /*for (int i = l; i <= r; ++ i){
        for (int j = i; j <= r; ++ j){
            ++ tot;
            for (int k = i; k <= j; ++ k){
                tmp[k - i] = input[k];
            }
            tmp[j - i + 1] = '\0';
            int len = strlen(tmp);
            for (int j = 0; j < len; ++ j){
                ++ cnt[len][tmp[j]];
            }
        }
    }*/
    for (int i = N - 1; i >= 2; -- i){
        for (int j = 0; j < N; ++ j){
            cnt[i][j] -= cnt[i - 1][j];
        }
    }
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i < N - 1; ++ i){
        for (int j = 0; j < N; ++ j){
            cnt[i][j] -= cnt[i + 1][j];
        }
    }
    for (int i = 1; i <= (n + 1) / 2; ++ i){
        int pos1 = i - 1, pos2 = n - i;
        for (int j = 0; j < N; ++ j){
            if (cnt[i][j] == 2){
                tmp[pos1] = tmp[pos2] = j;
            }
            else if (cnt[i][j] == 1){
                if (tmp[pos1] == '\0'){
                    tmp[pos1] = j;
                }
                else{
                    tmp[pos2] = j;
                }
            }
        }
    }
    for (int i = l, j = r; i <= j; ++ i, -- j){
        vec.push_back({i - 1, j - 1, tmp[i - l], tmp[j - l]});
    }
    return tmp;
}

int main(){
    int n;
    scanf("%d", &n);
    //scanf("%s", input + 1);
    std::string ans = ask(1, n);
    if (n == 1){
        printf("! %s\n", ans.c_str());
        return 0;
    }
    std::string ans1, ans2;
    if (n % 4 == 0){
        ans1 = ask(1, n / 2);
        ans2 = ask(n / 2, n);
    }
    else if (n % 4 == 1){
        ans1 = ask(1, n / 2);
        ans2 = ask(n / 2 + 1, n);
    }
    else if (n % 4 == 2){
        ans1 = ask(1, n / 2);
        ans2 = ask(n / 2, n);
    }
    else{
        ans1 = ask(1, n / 2);
        ans2 = ask(n / 2 + 1, n);
    }
    memset(tmp, 0, sizeof(tmp));
    while (true){
        for (auto u : vec){
            if (u.pos1 == u.pos2){
                tmp[u.pos1] = u.ch1;
            }
            else if (tmp[u.pos1] != '\0'){
                tmp[u.pos2] = u.ch1 ^ u.ch2 ^ tmp[u.pos1];
            }
            else if (tmp[u.pos2] != '\0'){
                tmp[u.pos1] = u.ch1 ^ u.ch2 ^ tmp[u.pos2];
            }
        }
        bool flag = true;
        for (int i = 0; i < n; ++ i){
            if (tmp[i] == '\0'){
                flag = false;
                break;
            }
        }
        if (flag){
            break;
        }
    }
    printf("! %s\n", tmp);
    //printf("%d %d\n", int(std::ceil(0.777 * (n + 1) * (n + 1))), tot);
    return 0;
}