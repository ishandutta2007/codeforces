#include <bits/stdc++.h>

const int N = 300010;

char s[N];
int pre[N], pre1[N], pre2[N];

void solve(){
    int n, test;
    scanf("%d%d", &n, &test);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++ i){
        if (i % 2 == 1){
            s[i] = s[i] == '+' ? '-' : '+';
        }
    }
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (s[i] == '+');
        pre1[i] = pre1[i - 1] + (s[i] == '-');
        pre2[i] = pre2[i - 1] + (s[i] == '+' ? 1 : -1);
    }
    std::map <int, std::vector <int>> map;
    for (int i = 1; i <= n; ++ i){
        int value = 2 * pre2[i - 1] + (s[i] == '+' ? 1 : -1);
        map[value].emplace_back(i);
    }
    while (test --){
        int l, r;
        scanf("%d%d", &l, &r);
        int x = pre[r] - pre[l - 1];
        int x1 = pre1[r] - pre1[l - 1];
        if (x == x1){
            puts("0");
            continue;
        }
        std::vector <int> ans;
        if ((r - l + 1) % 2 == 0){
            ans.emplace_back(l);
            ++ l;
        }
        auto &vec = map[pre2[r] + pre2[l - 1]];
        ans.emplace_back(*std::lower_bound(vec.begin(), vec.end(), l));
        int sz = ans.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz; ++ i){
            printf("%d%c", ans[i], " \n"[i == sz - 1]);
        }
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}