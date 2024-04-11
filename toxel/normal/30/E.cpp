#include <bits/stdc++.h>

const int N = 500010;

char s[N], t[N];
int p[N], zs[N];

void manacher(char *t, int *p){
    int cnt = strlen(t);
    for (int i = 1, l = 0, r = -1; i < cnt; ++ i){
        int k = i > r ? 1 : std::min(p[l + r - i], r - i + 1);
        while (t[i + k] == t[i - k]){
            ++ k;
        }
        p[i] = k --;
        if (i + k > r){
            l = i - k, r = i + k;
        }
    }
}

void ex_kmp(char *s, int *zs){
    int n = strlen(s);
    memset(zs, 0, sizeof(*zs) * n);
    for (int i = 1, l = 0, r = 0; i < n; ++ i){
        if (i <= r) zs[i] = std::min(zs[i - l], r - i + 1);
        while (i + zs[i] < n && s[i + zs[i]] == s[zs[i]]) ++ zs[i];
        if (i + zs[i] - 1 > r) l = i, r = i + zs[i] - 1;
    }
}

using pii = std::pair <int, int>;

std::vector<pii> vec1[N], vec2[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = n; i >= 1; -- i){
        t[i] = s[i - 1];
    }
    t[0] = '$';
    manacher(t, p);
    for (int i = 0; i < n; ++ i){
        p[i] = p[i + 1];
    }
    for (int i = 0; i < n; ++ i){
        t[i] = s[n - 1 - i];
        t[n + 1 + i] = s[i];
    }
    t[n] = '#';
    ex_kmp(t, zs);
    memcpy(zs, zs + n + 1, sizeof(zs[0]) * n);
    std::set <pii> set1, set2;
    for (int i = 0; i < n; ++ i){
        int pos = i + zs[i] - 1;
        vec1[pos].emplace_back(zs[i], i);
        set1.emplace(zs[i], i);
    }
    for (int i = 0; i < n; ++ i){
        int left = i - p[i] + 1, right = i + p[i] - 1;
        vec2[left].emplace_back(right, i);
    }
    int offset = 0, max = 0;
    pii ans1, ans2, ans3;
    for (int i = n - 1; i >= 0; -- i, -- offset){
        for (auto p : vec1[i]){
            set1.erase(p);
            int x = p.first - 1;
            set2.emplace(x - offset, p.second);
        }
        while (!set2.empty()){
            auto u = set2.begin();
            if (u -> first + offset <= 0){
                set2.erase(u);
            }
            else{
                break;
            }
        }
        for (auto p : vec2[i]){
            int mid = p.first - i + 1;
            if (mid > max){
                max = mid;
                ans1 = {-1, -1};
                ans2 = {i, mid};
                ans3 = {-1, -1};
            }
            if (!set1.empty()){
                auto u = std::prev(set1.end());
                int value = std::min(u -> first, n - 1 - p.first);
                if (value > 0 && mid + 2 * value > max){
                    max = mid + 2 * value;
                    ans1 = {u -> second, value};
                    ans2 = {i, mid};
                    ans3 = {n - value, value};
                }
            }
            if (!set2.empty()){
                auto u = std::prev(set2.end());
                int value = std::min(u -> first + offset, n - 1 - p.first);
                if (value > 0 && mid + 2 * value > max){
                    max = mid + 2 * value;
                    ans1 = {u -> second, value};
                    ans2 = {i, mid};
                    ans3 = {n - value, value};
                }
            }
        }
    }
    if (ans1.first == -1){
        printf("1\n%d %d\n", ans2.first + 1, ans2.second);
    }
    else{
        puts("3");
        printf("%d %d\n", ans1.first + 1, ans1.second);
        printf("%d %d\n", ans2.first + 1, ans2.second);
        printf("%d %d\n", ans3.first + 1, ans3.second);
    }
    return 0;
}