#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair <int, int>;
const int N = 1010;

ll area[N];

/*ll calc(int type, int i, int j, int k){
    static pii p[6] = {{-2, 1}, {3, -1}, {-2, -1}, {1, -2}, {0, 3}, {2, 2}};
    -- i, -- j, -- k;
    ll area = 1ll * (p[j].first - p[i].first) * (p[k].second - p[i].second) - 1ll * (p[j].second - p[i].second) * (p[k].first - p[i].first);
    if (type == 1){
        return std::abs(area);
    }
    return (area > 0) - (area < 0);
}*/

ll ask(int type, int i, int j, int k){
    printf("%d %d %d %d\n", type, i, j, k);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    //ret = calc(type, i, j, k);
    return ret;
}

void solve(std::vector <int> &vec, int begin){
    if (vec.empty()){
        return;
    }
    int pos = -1, n = vec.size();
    ll max = 0;
    for (int i = 0; i < n; ++ i){
        if (area[vec[i]] > max){
            max = area[vec[i]];
            pos = vec[i];
        }
    }
    std::vector <int> left, right;
    for (int i = 0; i < n; ++ i){
        if (vec[i] != pos){
            if (ask(2, begin, pos, vec[i]) > 0){
                left.push_back(vec[i]);
            }
            else{
                right.push_back(vec[i]);
            }
        }
    }
    std::sort(left.begin(), left.end(), [&](const int &p1, const int &p2){return area[p1] > area[p2];});
    std::sort(right.begin(), right.end(), [&](const int &p1, const int &p2){return area[p1] < area[p2];});
    std::vector <int> ret;
    for (auto u : right){
        ret.push_back(u);
    }
    ret.push_back(pos);
    for (auto u : left){
        ret.push_back(u);
    }
    vec = ret;
}

int main(){
    int n;
    scanf("%d", &n);
    std::vector <int> left, right;
    for (int i = 3; i <= n; ++ i){
        area[i] = ask(1, 1, 2, i);
        if (ask(2, 1, 2, i) > 0){
            left.push_back(i);
        }
        else{
            right.push_back(i);
        }
    }
    solve(left, 2);
    solve(right, 1);
    printf("0");
    printf(" 1");
    for (auto u : right){
        printf(" %d", u);
    }
    printf(" 2");
    for (auto u : left){
        printf(" %d", u);
    }
    puts("");
    fflush(stdout);
    return 0;
}