#include <bits/stdc++.h>

const int N = 1510;
using pvi = std::pair <std::vector <int>, int>;

void read(int &u){
    char ch;
    while (!isdigit(ch = getchar())){
    }
    u = ch - '0';
    while (isdigit(ch = getchar())){
        u = u * 10 + ch - '0';
    }
}

std::vector <int> a[N], b[N];
pvi vec1[N], vec2[N];
int id[N];
std::bitset <N> set[N], set1[N];
bool vis[N];

int main(){
    int n, m;
    read(n), read(m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int x;
            read(x);
            a[i].emplace_back(x);
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int x;
            read(x);
            b[i].emplace_back(x);
        }
    }
    for (int i = 0; i < n; ++ i){
        vec1[i] = {a[i], i};
        vec2[i] = {b[i], i};
    }
    std::sort(vec1, vec1 + n);
    std::sort(vec2, vec2 + n);
    for (int i = 0; i < n; ++ i){
        if (vec1[i].first != vec2[i].first){
            puts("-1");
            return 0;
        }
        id[vec2[i].second] = vec1[i].second;
    }
    for (int j = 0; j < m; ++ j){
        for (int i = 0; i < n - 1; ++ i){
            if (b[i][j] > b[i + 1][j]){
                set[j].set(i);
            }
            if (b[i][j] != b[i + 1][j]){
                set1[j].set(i);
            }
        }
    }
    for (int j = 0; j < m; ++ j){
        set1[j] = ~set1[j];
    }
    std::bitset <N> cur;
    for (int i = 0; i < n - 1; ++ i){
        cur.set(i);
    }
    std::vector <int> ans;
    for (int i = 0; i < 2 * m + 10; ++ i){
        bool found = false;
        int cnt = cur.count();
        for (int j = 0; j < m; ++ j){
            if (vis[j]){
                continue;
            }
            if ((cur & set[j]).any()){
                continue;
            }
            std::bitset <N> next = cur & set1[j];
            if (next.count() < cnt){
                vis[j] = true;
                found = true;
                cur = next;
                ans.emplace_back(j + 1);
                break;
            }
        }
        if (!found){
            break;
        }
    }
    for (int i = 0; i < n - 1; ++ i){
        if (cur.test(i) && id[i + 1] < id[i]){
            puts("-1");
            return 0;
        }
    }
    std::reverse(ans.begin(), ans.end());
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
    return 0;
}