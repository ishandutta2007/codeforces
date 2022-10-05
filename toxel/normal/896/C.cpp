#include<bits/stdc++.h>

const int moder = 1e9 + 7;
const int N = 100010;
typedef long long ll;
typedef std::pair <int, int> pii;
typedef std::pair <pii, ll> piii;

int a[N];
int seed;

int rnd(){
    int ret = seed;
    seed = (7ll * seed + 13) % 1000000007;
    return ret;
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
    int n, m, vmax;
    scanf("%d%d%d%d", &n, &m, &seed, &vmax);
    std::set <piii> set;
    for (int i = 1; i <= n; ++ i){
        a[i] = (rnd() % vmax) + 1;
        set.insert({{i, i}, a[i]});
    }
    for (int i = 0; i < m; ++ i){
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;

        if (l > r){ 
            std::swap(l, r);
        }

        int x, y;
        if (op == 3){
            x = (rnd() % (r - l + 1)) + 1;
        }
        else{
            x = (rnd() % vmax) + 1;
        }

        if (op == 4){
            y = (rnd() % vmax) + 1;
        }

        auto u = set.lower_bound({{l, 0}, 0});
        if (u == set.end() || u -> first.first > l){
            -- u;
        }
        std::vector <std::set <piii>::iterator> vec;
        while (u != set.end()){
            if (u -> first.first > r){
                break;
            }
            vec.push_back(u);
            ++ u;
        }
        if (op == 1){
            std::vector <piii> to_insert;
            for (auto v : vec){
                int ll = v -> first.first;
                int rr = v -> first.second;
                if (ll < l){
                    to_insert.push_back({{ll, l - 1}, v -> second});
                }
                if (rr > r){
                    to_insert.push_back({{r + 1, rr}, v -> second});
                }
                to_insert.push_back({{std::max(ll, l), std::min(rr, r)}, v -> second + x});
            }
            for (auto v : vec){
                set.erase(v);
            }
            for (auto v : to_insert){
                set.insert(v);
            }
        }
        else if (op == 2){
            std::vector <piii> to_insert;
            for (auto v : vec){
                int ll = v -> first.first;
                int rr = v -> first.second;
                if (ll < l){
                    to_insert.push_back({{ll, l - 1}, v -> second});
                }
                if (rr > r){
                    to_insert.push_back({{r + 1, rr}, v -> second});
                }
            }
            for (auto v : vec){
                set.erase(v);
            }
            for (auto v : to_insert){
                set.insert(v);
            }
            set.insert({{l, r}, x});
        }
        else if (op == 3){
            std::vector <std::pair <ll, int>> vvec;
            for (auto v : vec){
                int ll = v -> first.first;
                int rr = v -> first.second;
                ll = std::max(ll, l);
                rr = std::min(rr, r);
                vvec.push_back({v -> second, rr - ll + 1});
            }
            std::sort(vvec.begin(), vvec.end());
            for (auto u : vvec){
                if (u.second >= x){
                    printf("%lld\n", u.first);
                    break;
                }
                x -= u.second;
            }
        }
        else if (op == 4){
            std::vector <std::pair <ll, int>> vvec;
            for (auto v : vec){
                int ll = v -> first.first;
                int rr = v -> first.second;
                ll = std::max(ll, l);
                rr = std::min(rr, r);
                vvec.push_back({v -> second, rr - ll + 1});
            }
            int ans = 0;
            for (auto u : vvec){
                ans = (ans + 1ll * powermod(u.first % y, x, y) * u.second) % y;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}