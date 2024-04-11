#include<bits/stdc++.h>

int n, m;

const int N = 100010;

int a[N], b[N], c[N];

int encode(int x, int y){
    return x * m + y;
}

void print(int *a){
    puts("YES");
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            printf("%d%c", a[encode(i, j)] + 1, " \n"[j == m - 1]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    if (n == 3 && m == 4){
        puts("YES\n2 4 1 3\n7 5 8 6\n10 12 9 11");
        return 0;
    }
    if (n == 4 && m == 4){
        puts("YES\n2 4 1 3\n7 5 8 6\n10 12 9 11\n15 13 16 14");
        return 0;
    }
    if (n == 4 && m == 3){
        puts("YES\n4 8 6\n10 2 12\n1 11 3\n7 5 9");
        return 0;
    }
    bool flag = false;
    if (n > m){
        std::swap(n, m);
        flag = true;
    }
    if (m >= 5){
        for (int i = 0; i < n; ++ i){
            if (i & 1){
                for (int j = 1; j < m; j += 2){
                    a[encode(i, j >> 1)] = i * m + j;
                }
                for (int j = 0; j < m; j += 2){
                    a[encode(i, (j >> 1) + m / 2)] = i * m + j;
                }
            }
            else{
                for (int j = 0; j < m; j += 2){
                    a[encode(i, j >> 1)] = i * m + j;
                }
                for (int j = 1; j < m; j += 2){
                    a[encode(i, (j >> 1) + (m + 1) / 2)] = i * m + j;
                }
            }
        }
        if (!flag){
            print(a);
        }
        else{
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < m; ++ j){
                    b[encode(i, j)] = j * n + i;
                }
            }
            for (int i = 0; i < n * m; ++ i){
                c[i] = b[a[i]];
            }
            puts("YES");
            for (int i = 0; i < m; ++ i){
                for (int j = 0; j < n; ++ j){
                    printf("%d%c", c[encode(j, i)] + 1, " \n"[j == n - 1]);
                }
            }
        }
        return 0;
    }
    if (flag){
        std::swap(n, m);
    }
    for (int i = 0; i < n * m; ++ i){
        a[i] = i;
    }
    typedef std::pair <int, int> pii;
    std::set <pii> set;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (i < n - 1){
                set.insert({a[encode(i, j)], a[encode(i + 1, j)]});
            }
            if (j < m - 1){
                set.insert({a[encode(i, j)], a[encode(i, j + 1)]});
            }
        }
    }
    do{
        bool flag = true;
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (i < n - 1){
                    pii p = {a[encode(i, j)], a[encode(i + 1, j)]};
                    if (p.first > p.second){
                        std::swap(p.first, p.second);
                    }
                    if (set.count(p)){
                        flag = false;
                        break;
                    }
                }
                if (j < m - 1){
                    pii p = {a[encode(i, j)], a[encode(i, j + 1)]};
                    if (p.first > p.second){
                        std::swap(p.first, p.second);
                    }
                    if (set.count(p)){
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag){
                break;
            }
        }
        if (flag){
            print(a);
            return 0;
        }
    }
    while (std::next_permutation(a, a + n * m));
    puts("NO");
    return 0;
}