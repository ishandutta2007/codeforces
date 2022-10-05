#include <bits/stdc++.h>

const int N = 100010;
const int M = 10000010;
using pii = std::pair <int, int>;

int a[N], min[M];
std::vector <int> prime;
int cnt[M];
std::vector <pii> fact[N];

std::vector <int> calc(const std::vector <int> &vec){
    int n = vec.size();
    std::vector <int> ret(n);
    for (int i = 0; i < n; ++ i){
        for (auto p : fact[vec[i]]){
            ++ cnt[p.first];
        }
    }
    for (int i = 0; i < n; ++ i){
        for (auto p : fact[vec[i]]){
            ret[i] += p.second * cnt[p.first];
        }
        ret[i] = n - ret[i] - (a[vec[i]] > 1);
    }
    for (int i = 0; i < n; ++ i){
        for (auto p : fact[vec[i]]){
            -- cnt[p.first];
        }
    }
    return ret;
}

int main(){
    for (int i = 2; i < M; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (i * u >= M){
                break;
            }
            min[i * u] = u;
            if (i % u == 0){
                break;
            }
        }
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        std::vector <int> p;
        int x = a[i];
        while (x > 1){
            int tmp = min[x];
            p.push_back(tmp);
            while (x % tmp == 0){
                x /= tmp;
            }
        }
        for (int j = 0, sz = p.size(); j < 1 << sz; ++ j){
            int prod = 1;
            int cnt = 0;
            for (int k = 0; k < sz; ++ k){
                if (j >> k & 1){
                    prod *= p[k];
                    ++ cnt;
                }
            }
            fact[i].emplace_back(prod, cnt & 1 ? -1 : 1);
        }
    }
    std::vector <int> vec(n);
    for (int i = 0; i < n; ++ i){
        vec[i] = i;
    }
    std::vector <int> ret = calc(vec);
    auto min_pos = std::min_element(ret.begin(), ret.end());
    if (*min_pos >= n - 2){
        std::vector <int> ans;
        for (int i = 0; i < n; ++ i){
            int sum = 0;
            for (auto p : fact[i]){
                sum += cnt[p.first] * p.second;
            }
            sum = (i + 1) - sum - (a[i] > 1);
            for (auto p : fact[i]){
                ++ cnt[p.first];
            }
            if (sum == i){
                ans.push_back(i);
                if ((int) ans.size() == k){
                    break;
                }
            }
        }
        for (int i = 0; i < k; ++ i){
            printf("%d%c", ans[i] + 1, " \n"[i == k - 1]);
        }
        return 0;
    }
    int p1 = min_pos - ret.begin();
    int p2 = -1, p3 = -1;
    for (int i = 0; i < n; ++ i){
        if (i == p1){
            continue;
        }
        if (std::__gcd(a[p1], a[i]) == 1){
            if (p2 == -1){
                p2 = i;
            }
            else{
                p3 = i;
            }
        }
    }
    if (k == 3){
        printf("%d %d %d\n", p1 + 1, p2 + 1, p3 + 1);
        return 0;
    }
    vec.clear();
    for (int i = 0; i < n; ++ i){
        if (i != p1 && i != p2 && i != p3){
            vec.push_back(i);
        }
    }
    ret = calc(vec);
    int ccnt = 0;
    for (auto u : ret){
        ccnt += u == n - 3 - 1;
    }
    if (ccnt >= k){
        std::vector <int> ans;
        for (int i = 0; i < n - 3; ++ i){
            if (ret[i] == n - 3 - 1){
                ans.push_back(vec[i]);
            }
            if ((int) ans.size() == k){
                break;
            }
        }
        for (int i = 0; i < k; ++ i){
            printf("%d%c", ans[i] + 1, " \n"[i == k - 1]);
        }
        return 0;
    }
    int left = 1, right = vec.size();
    while (left < right){
        int mid = (left + right) / 2;
        std::vector <int> nvec;
        std::copy(vec.begin(), vec.begin() + mid, std::back_inserter(nvec));
        ret = calc(nvec);
        int ccnt = 3;
        for (int i = 0; i < mid; ++ i){
            ccnt += ret[i] < mid - 1;
        }
        if (ccnt >= k){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    vec.resize(left);
    ret = calc(vec);
    std::set <int> set, set1;
    set.insert(vec[left - 1]);
    set1.insert(vec[left - 1]);
    vec.resize(left - 1);
    std::vector <int> nret = calc(vec);
    for (int i = 0; i < left - 1; ++ i){
        if (nret[i] < left - 1 - 1){
            set.insert(vec[i]);
        }
        if (ret[i] < left - 1){
            set1.insert(vec[i]);
        }
    }
    for (auto u : set1){
        if (!set.count(u)){
            set.insert(u);
        }
        if ((int) set.size() + 3 == k + 1){
            break;
        }
    }
    if ((int) set.size() + 3 < k + 1){
        set.insert(p3);
    }
    set.insert(p1);
    set.insert(p2);
    ret.clear();
    for (auto u : set){
        ret.push_back(u);
    }
    for (int i = 0; i < k; ++ i){
        printf("%d%c", ret[i] + 1, " \n"[i == k - 1]);
    }
    return 0;
}