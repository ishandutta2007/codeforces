#include <bits/stdc++.h>

struct P{
    int x, y, z;
    int id;

    bool operator < (const P &p)const{
        if (x != p.x) return x < p.x;
        if (y != p.y) return y < p.y;
        return z < p.z;
    }
};

const int N = 50010;

int x[N], y[N], z[N];

int main(){
    int n;
    scanf("%d", &n);
    std::map <int, std::vector <P>> map;
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        P p = {x[i], y[i], z[i], i};
        map[z[i]].push_back(p);
    }
    std::vector <P> vvec;
    for (auto &u : map){
        std::map <int, std::vector <P>> mmap;
        for (auto v : u.second){
            mmap[v.y].push_back(v);
        }
        std::vector <P> vec;
        for (auto &v : mmap){
            std::sort(v.second.begin(), v.second.end());
            int sz = v.second.size();
            for (int i = 1; i < sz; i += 2){
                printf("%d %d\n", v.second[i - 1].id, v.second[i].id);
            }
            if (sz & 1){
                vec.push_back(v.second.back());
            }
        }
        int sz = vec.size();
        for (int i = 1; i < sz; i += 2){
            printf("%d %d\n", vec[i - 1].id, vec[i].id);
        }
        if (sz & 1){
            vvec.push_back(vec.back());
        }
    }
    int sz = vvec.size();
    for (int i = 1; i < sz; i += 2){
        printf("%d %d\n", vvec[i - 1].id, vvec[i].id);
    }
    return 0;
}