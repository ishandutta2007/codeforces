#include<bits/stdc++.h>

const int N = 1000010;
const int M = 80000;
typedef std::pair <std::vector <int>, std::vector <int>> pvv;
typedef std::pair <int, int> pii;

int min[N], sigma[N], cnt[N];
std::vector <int> prime;

std::vector <int> getfact(int n){
    std::vector <int> fact;
    while (n > 1){
        int cnt = 0, tmp = min[n];
        while (n % tmp == 0){
            ++ cnt;
            n /= tmp;
        }
        fact.push_back(cnt);
    }
    std::sort(fact.begin(), fact.end());
    return fact;
}

int calc(const std::vector <int> &vec){
    int ret = 1;
    for (auto u : vec){
        ret *= u + 1;
    }
    return ret;
}

std::map <pvv, int> ans;

void init(){
    sigma[1] = 1;
    std::set <int> set;
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
            sigma[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 0, k, sz = prime.size(); j < sz && i * prime[j] < N; ++ j){
            min[k = i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                cnt[k] = cnt[i] + 1;
                sigma[k] = 1ll * sigma[i] * (cnt[k] + 1) / cnt[k];
                break;
            }
            sigma[k] = sigma[i] * 2;
            cnt[k] = 1;
        }
    }
    for (int i = 1; i < N; ++ i){
        set.insert(sigma[i]);
    }
    std::set <std::vector <int>> vset;
    for (int i = 1; i < N; ++ i){
        vset.insert(getfact(i));
    }
    std::map <std::vector <int>, std::vector <pii>> map;
    for (auto &u : vset){
        std::vector <int> vec(M, INT_MAX);
        vec[calc(u)] = 0;
        std::set <std::vector <int>> now;
        now.insert(u);
        for (int dis = 1; dis <= 8; ++ dis){
            std::set <std::vector <int>> tmp;
            for (auto &v : now){
                if (v.empty()){
                    tmp.insert({1});
                    continue;
                }
                if (v[0] == 1){
                    std::vector <int> vvec;
                    for (int i = 1, sz = v.size(); i < sz; ++ i){
                        vvec.push_back(v[i]);
                    }
                    tmp.insert(vvec);
                }
                int sz = v.size();
                for (int i = 0; i < sz; ++ i){
                    if ((i == 0 || v[i] > v[i - 1]) && v[i] > 1){
                        std::vector <int> vvec = v;
                        -- vvec[i];
                        tmp.insert(vvec);
                    }
                    if (i == sz - 1 || v[i] < v[i + 1]){
                        std::vector <int> vvec = v;
                        ++ vvec[i];
                        tmp.insert(vvec);
                    }
                }
                std::vector <int> vvec = v;
                vvec.push_back(1);
                std::sort(vvec.begin(), vvec.end());
                tmp.insert(vvec);
            }
            for (auto &v : tmp){
                int x = calc(v);
                vec[x] = std::min(vec[x], dis);
            }
            now = tmp;
        }
        std::vector <pii> vvec;
        for (int i = 0; i < M; ++ i){
            if (vec[i] != INT_MAX){
                vvec.push_back({i, vec[i]});
            }
        }
        map[u] = vvec;
    }
    for (auto &u : vset){
        for (auto &v : vset){
            int min = INT_MAX;
            auto &tmp1 = map[u];
            auto &tmp2 = map[v];
            int sz1 = tmp1.size();
            int sz2 = tmp2.size();
            for (int i = 0, j = 0; i < sz1 && j < sz2; ){
                if (tmp1[i].first < tmp2[j].first){
                    ++ i;
                }
                else if(tmp1[i].first > tmp2[j].first){
                    ++ j;
                }
                else{
                    min = std::min(min, tmp1[i].second + tmp2[j].second);
                    ++ i, ++ j;
                }
            }
            ans[{u, v}] = min;
        }
    }
}

int main(){
    init();
    int test;
    scanf("%d", &test);
    while (test --){
        int a, b;
        scanf("%d%d", &a, &b);
        std::vector <int> veca = getfact(a);
        std::vector <int> vecb = getfact(b);
        printf("%d\n", ans[{veca, vecb}]);
    }
    return 0;
}