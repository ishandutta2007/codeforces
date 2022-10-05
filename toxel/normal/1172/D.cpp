#include <bits/stdc++.h>

struct Portal{
    int x1, y1, x2, y2;

    Portal():x1(0), y1(0), x2(0), y2(0){}
    Portal(int x1, int y1, int x2, int y2):x1(x1), y1(y1), x2(x2), y2(y2){}

    void print(){
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
};

const int N = 1010;

int r[N], c[N];
int ir[N], ic[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &r[i]);
        ir[i] = i;
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
        ic[i] = i;
    }
    std::vector <Portal> ans;
    for (int i = 1; i <= n; ++ i){
        if (r[ir[i]] == i && c[ic[i]] == i){
            continue;
        }
        int posr = std::find_if(ir + i, ir + n + 1, [&](const int &x){return r[x] == i;}) - ir;
        int posc = std::find_if(ic + i, ic + n + 1, [&](const int &x){ return c[x] == i;}) - ic;
        ans.emplace_back(posr, i, i, posc);
        std::swap(ir[i], ir[posr]);
        std::swap(ic[i], ic[posc]);
    }
    for (int i = 1; i <= n; ++ i){
        assert(r[ir[i]] == i);
        assert(c[ic[i]] == i);
    }
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        u.print();
    }
    return 0;
}