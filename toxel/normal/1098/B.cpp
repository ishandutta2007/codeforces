#include<bits/stdc++.h>

const int N = 300010;
typedef std::pair <int, int> pii;

std::string s[N];
char tmp[N];
int minx[N][12], miny[N][12];
char zzh[] = "ATGC";

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", tmp);
        s[i] = tmp;
    }
    std::map <pii, int> map;
    for (int i = 0; i < n; ++ i){
        int cnt = 0;
        for (int u = 0; u < 4; ++ u){
            for (int v = 0; v < 4; ++ v){
                if (u == v) continue;
                map[{u, v}] = cnt;
                for (int j = 0; j < m; ++ j){
                    if ((!(j & 1) && s[i][j] != zzh[u]) || ((j & 1) && s[i][j] != zzh[v])){
                        ++ minx[i][cnt];
                    }
                }
                ++ cnt;
            }
        }
    }
    for (int i = 0; i < m; ++ i){
        int cnt = 0;
        for (int u = 0; u < 4; ++ u){
            for (int v = 0; v < 4; ++ v){
                if (u == v) continue;
                for (int j = 0; j < n; ++ j){
                    if ((!(j & 1) && s[j][i] != zzh[u]) || ((j & 1) && s[j][i] != zzh[v])){
                        ++ miny[i][cnt];
                    }
                }
                ++ cnt;
            }
        }
    }
    std::vector <int> oppo[12];
    std::vector <int> same[12];
    for (int i = 0; i < 4; ++ i){
        for (int j = 0; j < 4; ++ j){
            if (i == j) continue;
            for (int u = 0; u < 4; ++ u){
                if (u == i || u == j) continue;
                for (int v = 0; v < 4; ++ v){
                    if (v == i || v == j || v == u) continue;
                    oppo[map[{i, j}]].push_back(map[{u, v}]);
                }
            }
            same[map[{i, j}]].push_back(map[{i, j}]);
            same[map[{i, j}]].push_back(map[{j, i}]);
        }
    }
    int min = INT_MAX, type1, type2;
    for (int i = 0; i < 12; ++ i){
        int sum = 0;
        for (int j = 0; j < n; ++ j){
            int mmin = INT_MAX;
            auto &vec = j & 1 ? oppo[i] : same[i];
            for (auto u : vec){
                mmin = std::min(mmin, minx[j][u]);
            }
            sum += mmin;
        }
        if (sum < min){
            min = sum;
            type1 = 0;
            type2 = i;
        }
    }
    for (int i = 0; i < 12; ++ i){
        int sum = 0;
        for (int j = 0; j < m; ++ j){
            int mmin = INT_MAX;
            auto &vec = j & 1 ? oppo[i] : same[i];
            for (auto u : vec){
                mmin = std::min(mmin, miny[j][u]);
            }
            sum += mmin;
        }
        if (sum < min){
            min = sum;
            type1 = 1;
            type2 = i;
        }
    }
    if (type1 == 0){
        for (int i = 0; i < n; ++ i){
            int mmin = INT_MAX;
            int type;
            auto &vec = i & 1 ? oppo[type2] : same[type2];
            for (auto u : vec){
                if (mmin > minx[i][u]){
                    mmin = minx[i][u];
                    type = u;
                }
            }
            int u, v;
            for (int j = 0; j < 4; ++ j){
                for (int k = 0; k < 4; ++ k){
                    if (j == k) continue;
                    if (map[{j, k}] == type){
                        u = j;
                        v = k;
                    }
                }
            }
            for (int j = 0; j < m; ++ j){
                s[i][j] = j & 1 ? zzh[v] : zzh[u];
            } 
        }
    }
    else{
        for (int i = 0; i < m; ++ i){
            int mmin = INT_MAX;
            int type;
            auto &vec = i & 1 ? oppo[type2] : same[type2];
            for (auto u : vec){
                if (mmin > miny[i][u]){
                    mmin = miny[i][u];
                    type = u;
                }
            }
            int u, v;
            for (int j = 0; j < 4; ++ j){
                for (int k = 0; k < 4; ++ k){
                    if (j == k) continue;
                    if (map[{j, k}] == type){
                        u = j;
                        v = k;
                    }
                }
            }
            for (int j = 0; j < n; ++ j){
                s[j][i] = j & 1 ? zzh[v] : zzh[u];
            } 
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%s\n", s[i].c_str());
    }
    return 0;
}