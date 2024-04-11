#include <bits/stdc++.h>

const int N = 200010;

int cnt[N];

void solve(){
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i <= n; ++ i){
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++ i){
        int col;
        scanf("%d", &col);
        cnt[col] += i <= l ? 1 : -1;
    }
    std::deque <int> po, pe, no, ne;
    for (int i = 1; i <= n; ++ i){
        if (cnt[i] > 0){
            (cnt[i] & 1 ? po : pe).emplace_back(std::abs(cnt[i]));
        }
        else if (cnt[i] < 0){
            (cnt[i] & 1 ? no : ne).emplace_back(std::abs(cnt[i]));
        }
    }
    int ans = 0;
    while (true){
        while (!pe.empty() && pe.front() == 0){
            pe.pop_front();
        }
        while (!ne.empty() && ne.front() == 0){
            ne.pop_front();
        }
        if (po.empty() && pe.empty() && no.empty() && ne.empty()){
            break;
        }
        if (!po.empty() && !no.empty()){
            int x = po.front(), y = no.front();
            po.pop_front(), no.pop_front();
            ++ ans;
            -- x, -- y;
            pe.emplace_back(x);
            ne.emplace_back(y);
        }
        else if (!po.empty() && !ne.empty()){
            int x = po.front(), y = ne.front();
            po.pop_front(), ne.pop_front();
            ++ ans;
            -- x, -- y;
            pe.emplace_back(x);
            no.emplace_back(y);
        }
        else if (!pe.empty() && !no.empty()){
            int x = pe.front(), y = no.front();
            pe.pop_front(), no.pop_front();
            ++ ans;
            -- x, -- y;
            po.emplace_back(x);
            ne.emplace_back(y);
        }
        else if (!pe.empty() && !ne.empty()){
            int x = pe.front(), y = ne.front();
            pe.pop_front(), ne.pop_front();
            ++ ans;
            -- x, -- y;
            po.emplace_back(x);
            no.emplace_back(y);
        }
        else{
            if (pe.empty() && po.empty()){
                pe.swap(ne);
                po.swap(no);
            }
            int sum = 0;
            for (auto u : pe){
                sum += u;
            }
            for (auto u : po){
                sum += u;
            }
            ans += sum / 2;
            ans += int(po.size()) / 2;
            break;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}