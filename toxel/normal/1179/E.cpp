#include <bits/stdc++.h>

using ll = long long;

const int N = 1010;
const ll MAX = (ll) 1e18;

int n;

int rand(int n){
    return rand() % n;
}

ll ask(int id, ll pos){
    printf("? %d %lld\n", id + 1, pos);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}

ll left[N], right[N];

void solve(std::vector <int> vec, ll l, ll r, ll l_value, ll r_value){
    if ((int) vec.size() == 1){
        left[vec[0]] = l;
        right[vec[0]] = r;
        return;
    }
    ll diff = (r_value - l_value) / vec.size();
    ll target;
    if (vec.size() % 2 == 0){
        target = (l_value + r_value) / 2;
    }
    else{
        target = (l_value + r_value - diff) / 2;
    }
    int target_sit = ((int) vec.size() + 1) / 2;
    std::vector <int> small, big, possible = vec;
    ll cur_l = l, cur_r = r;
    while (true){
        int pos = possible[rand(possible.size())];
        std::vector <std::pair <ll, int>> value;
        ll l1 = cur_l, r1 = cur_r;
        while (l1 < r1){
            ll mid = (l1 + r1) / 2;
            if (ask(pos, mid) >= target){
                r1 = mid;
            }
            else{
                l1 = mid + 1;
            }
        }
        for (auto u : possible){
            value.emplace_back(ask(u, l1), u);
        }
        std::sort(value.begin(), value.end());
        int sit = target_sit - (int) small.size();
        if (value[sit].first < target){
            std::vector <int> npossible;
            for (auto p : value){
                if (p.first >= target){
                    big.push_back(p.second);
                }
                else{
                    npossible.push_back(p.second);
                }
            }
            possible = npossible;
            cur_l = l1 + 1;
        }
        else if (value[sit].first > target){
            std::vector <int> npossible;
            for (auto p : value){
                if (p.first <= target){
                    small.push_back(p.second);
                }
                else{
                    npossible.push_back(p.second);
                }
            }
            possible = npossible;
            cur_r = l1 - 1;
        }
        else{
            for (int i = 0; i < sit; ++ i){
                small.push_back(value[i].second);
            }
            for (int i = sit; i < (int) value.size(); ++ i){
                big.push_back(value[i].second);
            }
            solve(small, l1, r, target, r_value);
            solve(big, l, l1, l_value, target);
            break;
        }
    }
}

int main(){
    srand((unsigned) time(nullptr));
    ll l;
    scanf("%d%lld", &n, &l);
    std::vector <int> vec(n);
    for (int i = 0; i < n; ++ i){
        vec[i] = i;
    }
    solve(vec, 0, MAX, 0, l);
    puts("!");
    for (int i = 0; i < n; ++ i){
        printf("%lld %lld\n", left[i], right[i]);
    }
    return 0;
}