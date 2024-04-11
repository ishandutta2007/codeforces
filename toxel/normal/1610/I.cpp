#include <bits/stdc++.h>

const int N = 300010;

int sg[N];
std::vector <int> e[N];
bool del[N];
int pa[N];

void init(int u, int fa){
    pa[u] = fa;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        init(v, u);
        sg[u] ^= sg[v] + 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    init(1, 0);
    putchar(sg[1] > 0 ? '1' : '2');
    for (int i = 2; i <= n; ++ i){
        if (!del[i]){
            std::vector <int> vec;
            int x = i;
            while (x != 1){
                vec.emplace_back(x);
                x = pa[x];
            }
            vec.emplace_back(1);
            std::reverse(vec.begin(), vec.end());
            int sz = vec.size();
            for (int j = 1; j < sz; ++ j){
                int u = vec[j];
                for (auto v : e[u]){
                    if (v == vec[j - 1]){
                        continue;
                    }
                    if (del[v]){
                        continue;
                    }
                    if (j < sz - 1 && v == vec[j + 1]){
                        continue;
                    }
                    sg[1] ^= sg[v] + 1;
                    pa[v] = 1;
                }
            }
            sg[1] ^= sg[vec[1]] + 1;
            sg[1] ^= (vec.size() + 1) % 2;
            for (int j = 1; j < sz; ++ j){
                del[vec[j]] = true;
            }
        }
        putchar(sg[1] > 0 ? '1' : '2');
        // printf("%d\n", sg[1]);
    }
    puts("");
    return 0;
}