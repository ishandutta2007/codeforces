#include <bits/stdc++.h>

int n;
std::vector<std::pair<std::pair<int, int>, int> > A;
std::vector<int> ans;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
    ans.resize(n);
    for(int i = 0; i < n; ++i){
        int a, b;
        std::cin >> a >> b;
        A.push_back(std::make_pair(std::make_pair(a, b), i));
    }
    std::sort(A.begin(), A.end());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;
    auto it = A.begin();
    int x = 1;
    while(it != A.end() && (que.empty() || it->first.first <= x))
            que.push(std::make_pair(it->first.second, it->second)), x = it->first.first, it++;
    while(!que.empty()){
        int cur = que.top().second;
        que.pop();
        ans[cur] = x++;
        while(it != A.end() && (que.empty() || it->first.first <= x))
            que.push(std::make_pair(it->first.second, it->second)), x = it->first.first, it++;
    };
    for(auto i : ans) std::cout << i << " ";
    return 0;
}