#include <bits/stdc++.h>

const int N = 1010;
const int INF = int(2e6);

int n;
int x[N], y[N];
std::vector <int> ans;

void solve(){
    std::vector <int> vec[2][2];
    for (int i = 0; i < n; ++ i){
        vec[x[i] % 2][y[i] % 2].emplace_back(i + 1);
    }
    if (vec[0][1].empty() && vec[1][0].empty()){
        if (vec[0][0].empty()){
            for (int i = 0; i < n; ++ i){
                x[i] -= 1, y[i] -= 1;
                x[i] /= 2, y[i] /= 2;
            }
            solve();
            return;
        }
        if (vec[1][1].empty()){
            for (int i = 0; i < n; ++ i){
                x[i] /= 2, y[i] /= 2;
            }
            solve();
            return;
        }
        ans = vec[0][0];
        return;
    }
    if (vec[0][0].empty() && vec[1][1].empty()){
        if (vec[0][1].empty()){
            for (int i = 0; i < n; ++ i){
                x[i] -= 1;
                x[i] /= 2, y[i] /= 2;
            }
            solve();
            return;
        }
        if (vec[1][0].empty()){
            for (int i = 0; i < n; ++ i){
                y[i] -= 1;
                x[i] /= 2, y[i] /= 2;
            }
            solve();
            return;
        }
        ans = vec[0][1];
        return;
    }
    ans = vec[0][0];
    for (auto u : vec[1][1]){
        ans.push_back(u);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
        x[i] += INF;
        y[i] += INF;
    }
    solve();
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
    return 0;
}