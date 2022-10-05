#include <bits/stdc++.h>

using ll = long long;
const int N = 5010;

struct P{
    ll x, y;

    P operator -(const P &p)const{return {x - p.x, y - p.y};}

    ll operator ^(const P &p)const{
        return x * p.y - y * p.x;
    }

    ll operator %(const P &p)const{
        return x * p.x + y * p.y;
    }

    int type()const{
        if (y) return y > 0 ? 0 : 1;
        return x > 0 ? 0 : 1;
    }

    ll abs2()const{
        return *this % *this;
    }

    bool operator <(const P &p)const{
        int t1 = type(), t2 = p.type();
        if (t1 != t2) return t1 < t2;
        ll value = *this ^ p;
        if (value) return value > 0;
        return abs2() < p.abs2();
    }

    bool operator ==(const P &p)const{
        return !(*this < p) && !(p < *this);
    }

    void scan(){
        scanf("%lld%lld", &x, &y);
    }
};

P p[N];
bool vis[N];
std::vector <int> ans;

bool cmp(const P &p1, const P &p){
    if (p1.x == p.x) return p1.y < p.y;
    return p1.x < p.x;
}

void dfs(int n){
    int first = -1;
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            first = i;
            break;
        }
    }
    if (first == -1){
        return;
    }
    std::vector <int> vec;
    for (int i = 0; i < n; ++ i){
        if (!vis[i] && i != first){
            vec.emplace_back(i);
        }
    }
    if (vec.empty()){
        return;
    }
    int cur = 0;
    int sz = vec.size();
    for (int i = 1; i < sz; ++ i){
        if (p[vec[i]] - p[first] < p[vec[cur]] - p[first]){
            cur = i;
        }
    }
    std::vector <int> this_round;
    for (int i = 0; i < sz; ++ i){
        if (p[vec[i]] - p[first] == p[vec[cur]] - p[first]){
            this_round.emplace_back(i);
            vis[vec[i]] = true;
        }
    }
    dfs(n);
    std::sort(this_round.begin(), this_round.end());
    if (ans.empty()){
        ans.emplace_back(first);
        sz = this_round.size();
        for (int l = 0, r = sz - 1; l < r; ++ l, -- r){
            ans.emplace_back(this_round[r]);
            ans.emplace_back(this_round[l]);
        }
        return;
    }

}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        p[i].scan();
    }
    std::vector <int> ans = {0};
    int cur = 0;
    vis[0] = true;
    for (int i = 0; i < n - 1; ++ i){
        ll max = 0;
        int sit = -1;
        for (int j = 0; j < n; ++ j){
            if (!vis[j]){
                if ((p[j] - p[cur]).abs2() > max){
                    max = (p[j] - p[cur]).abs2();
                    sit = j;
                }
            }
        }
        ans.emplace_back(sit);
        vis[sit] = true;
        cur = sit;
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
    }
    return 0;
}