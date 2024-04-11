#include <bits/stdc++.h>

typedef std::pair <int, int> pii;
typedef std::pair <int, std::vector <int>> piv;
const int N = 300010;

int a[N], b[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &a[i], &b[i]);
    }
    std::vector <pii> vec;
    for (int i = 0; i < n; ++ i){
        if (a[i] < b[i]){
            vec.push_back({b[i], i});
        }
    }
    std::sort(vec.begin(), vec.end(), std::greater <pii>());
    piv ans1;
    ans1.first = vec.size();
    for (auto u : vec){
        ans1.second.push_back(u.second + 1);
    }
    vec.clear();
    for (int i = 0; i < n; ++ i){
        if (a[i] > b[i]){
            vec.push_back({-b[i], i});
        }
    }
    std::sort(vec.begin(), vec.end(), std::greater <pii>());
    piv ans2;
    ans2.first = vec.size();
    for (auto u : vec){
        ans2.second.push_back(u.second + 1);
    }
    ans1 = std::max(ans1, ans2);
    printf("%d\n", ans1.first);
    for (int i = 0; i < ans1.first; ++ i){
        printf("%d%c", ans1.second[i], " \n"[i == ans1.first - 1]);
    }
    return 0;
}