#include<bits/stdc++.h>

const int N = 100010;

bool inner;

struct elem{
    int x, y, z;
    bool isquery;
    int id;

    bool operator <(const elem &e)const{
        if (!inner){
            if (x != e.x) return x < e.x;
        }
        if (y != e.y) return y < e.y;
        if (z != e.z) return z < e.z;
        return isquery < e.isquery;
    }
};

int c[N];
int ans[N];

void add(int sit, int value){
    ++ sit;
    for ( ; sit < N; sit += sit & -sit){
        c[sit] += value;
    }
}

int query(int sit){
    ++ sit;
    int ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

void solve(std::vector <elem> &vec, int l, int r){
    if (l >= r){
        return;
    }
    int mid = (l + r) >> 1;
    solve(vec, l, mid);
    solve(vec, mid + 1, r);
    std::vector <elem> vvec;
    for (int i = l; i <= mid; ++ i){
        if (!vec[i].isquery){
            vvec.push_back(vec[i]);
        }
    }
    for (int i = mid + 1; i <= r; ++ i){
        if (vec[i].isquery){
            vvec.push_back(vec[i]);
        }
    }
    inner = true;
    std::sort(vvec.begin(), vvec.end());
    for (auto u : vvec){
        if (!u.isquery){
            add(u.z, 1);
        }
        else{
            if (query(u.z)){
                ans[u.id] = 2;
            }
        }
    }
    for (auto u : vvec){
        if (!u.isquery){
            add(u.z, -1);
        }
    }
}

void solve(std::vector <elem> vec){
    inner = false;
    std::sort(vec.begin(), vec.end());
    solve(vec, 0, (int) vec.size() - 1);
    /*for (auto u : vec){
        for (auto v : vec){
            if (u.isquery && !v.isquery){
                if (u.x >= v.x && u.y >= v.y && u.z >= v.z){
                    ans[u.id] = 2;
                }
            }
        }
    }*/
}

std::vector <elem> vec[8];

int check(int type, int l, int r, int sit){
    if (l <= sit && sit <= r){
        return 0;
    }
    if (type == 1){
        return sit > r ? sit - r : -1;
    }
    return sit < l ? l - sit : -1;
}

int main(){
    int xmax, ymax, zmax, n, m, k;
    scanf("%d%d%d%d%d%d", &xmax, &ymax, &zmax, &n, &m, &k);
    int xmin = 1, ymin = 1, zmin = 1;
    for (int i = 0; i < n; ++ i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        xmax = std::min(xmax, x);
        xmin = std::max(xmin, x);
        ymax = std::min(ymax, y);
        ymin = std::max(ymin, y);
        zmax = std::min(zmax, z);
        zmin = std::max(zmin, z);
    }
    bool invalid = false;
    for (int i = 0; i < m; ++ i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (xmax <= x && x <= xmin && ymax <= y && y <= ymin && zmax <= z && z <= zmin){
            invalid = true;
        }
        else{
            for (int j = 0; j < 8; ++ j){
                int cx = check(j >> 2 & 1, xmax, xmin, x);
                int cy = check(j >> 1 & 1, ymax, ymin, y);
                int cz = check(j >> 0 & 1, zmax, zmin, z);
                if (cx >= 0 && cy >= 0 && cz >= 0){
                    vec[j].push_back({cx, cy, cz, false, 0});
                }
            }
        }
    }
    for (int i = 0; i < k; ++ i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (xmax <= x && x <= xmin && ymax <= y && y <= ymin && zmax <= z && z <= zmin){
            continue;
        }
        int cx = x >= xmax, dx = x > xmin ? x - xmin : x < xmax ? xmax - x : 0;
        int cy = y >= ymax, dy = y > ymin ? y - ymin : y < ymax ? ymax - y : 0;
        int cz = z >= zmax, dz = z > zmin ? z - zmin : z < zmax ? zmax - z : 0;
        vec[(cx << 2) | (cy << 1) | cz].push_back({dx, dy, dz, true, i});
        ans[i] = 1;
    }
    if (invalid){
        puts("INCORRECT");
        return 0;
    }
    for (int i = 0; i < 8; ++ i){
        solve(vec[i]);
    }
    puts("CORRECT");
    for (int i = 0; i < k; ++ i){
        puts(ans[i] == 0 ? "OPEN" : ans[i] == 1 ? "UNKNOWN" : "CLOSED");
    }
    return 0;
}