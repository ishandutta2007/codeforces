#include<bits/stdc++.h>

const int MAX = 100000;
const int N = 100;

int randint(){
    return rand() % 3;
}

int powermod(int a, int exp, int moder){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int main(){
    srand((unsigned) time(NULL));
    int u, v, p;
    scanf("%d%d%d", &u, &v, &p);
    std::map <int, std::vector <int>> Hash1;
    for (int i = 0; i < MAX; ++ i){
        std::vector <int> vec;
        int x = u;
        for (int j = 0; j < N; ++ j){
            int type = randint();
            switch (type){
                case 0: ++ x; x -= x >= p ? p : 0; break;
                case 1: -- x; x += x < 0 ? p : 0; break;
                case 2: x = powermod(x, p - 2, p); break;
            }
            vec.push_back(type);
        }
        Hash1[x] = vec;
    }
    while (true){
        std::vector <int> vec;
        int x = v;
        for (int j = 0; j < N; ++ j){
            int type = randint();
            switch (type){
                case 0: ++ x; x -= x >= p ? p : 0; break;
                case 1: -- x; x += x < 0 ? p : 0; break;
                case 2: x = powermod(x, p - 2, p); break;
            }
            vec.push_back(type);
            if (Hash1.count(x)){
                printf("%d\n", N + (int) vec.size());
                for (auto v : Hash1[x]){
                    printf("%d ", v + 1);
                }
                std::reverse(vec.begin(), vec.end());
                for (auto v : vec){
                    printf("%d ", v == 0 ? 2 : v == 1 ? 1 : 3);
                }
                puts("\n");
                return 0;
            }
        }
    }
}