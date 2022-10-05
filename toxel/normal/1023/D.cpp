#include<bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;

int a[N], left[N], right[N], ans[N];
std::vector <pii> vec[N];

int main(){
    memset(left, 0x7f, sizeof(left));
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        if (a[i]){
            left[a[i]] = std::min(left[a[i]], i);
            right[a[i]] = std::max(right[a[i]], i);
        }
    }
    for (int i = 1; i <= q; ++ i){
        if (right[i]){
            vec[left[i]].push_back({i, 0});
            vec[right[i]].push_back({i, 1});
        }
    }
    std::set <int> set;
    for (int i = 1; i <= n; ++ i){
        for (auto u : vec[i]){
            if (!u.second){
                set.insert(u.first);
            }
        }
        if (!set.empty()){
            ans[i] = *(set.rbegin());
        }
        for (auto u : vec[i]){
            if (u.second){
                set.erase(u.first);
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (a[i] && a[i] != ans[i]){
            puts("NO");
            return 0;
        }
    }
    int cntq = 0, cnt0 = 0;
    for (int i = 1; i <= n; ++ i){
        cntq += a[i] == q;
        cnt0 += !a[i];
    }
    if (!cntq){
        if (!cnt0){
            puts("NO");
            return 0;
        }
        for (int i = 1; i <= n; ++ i){
            if (!a[i]){
                a[i] = q;
                break;
            }
        }
    }
    int sit = 0;
    for (int i = 1; i <= n; ++ i){
        if (a[i]){
            sit = i;
            break;
        }
    }
    for (int i = 1; i < sit; ++ i){
        a[i] = a[sit];
    }
    int now = a[sit];
    for (int i = sit + 1; i <= n; ++ i){
        if (a[i]){
            now = a[i];
        }
        else{
            a[i] = now;
        }
    }
    puts("YES");
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}