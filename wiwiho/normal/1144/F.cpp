#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

bool check(std::queue<int> &queue, std::vector<std::vector<int> > &eov, std::vector<std::pair<int, int> > &edge,
        int* vertices){
    bool ans = true;
    while(!queue.empty()){
        
        int now = queue.front();

        for(auto it = eov[now].begin(); it != eov[now].end(); it++){
            int target = (edge[*it].first == now) ? edge[*it].second : edge[*it].first;
            
            if(vertices[target] == 0){
                vertices[target] = vertices[now] == 1 ? 2 : 1;
                queue.push(target);
            }
            else if(vertices[target] == vertices[now]){
                ans = false;
                goto outside;
            }
        }
        queue.pop();
    }
    outside:
    return ans;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n,m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int> > edge(m);
    std::vector<std::vector<int> > eov(n + 1);
    for(int i = 0; i < m; i++){
        std::cin >> edge[i].first >> edge[i].second;
        eov[edge[i].first].push_back(i);
        eov[edge[i].second].push_back(i);
    }

    int vertices[n + 1]; //0=unknown 1=out 2=in
    for(int i = 1; i < n + 1; i++){
        vertices[i] = 0;
    }

    std::queue<int> queue1;
    queue1.push(1);
    vertices[1] = 1;
    bool ans1 = check(queue1, eov, edge, vertices);

    bool ans2;

    if(!ans1){
        for(int i = 1; i < n + 1; i++){
        vertices[i] = 0;
        }

        std::queue<int> queue2;
        queue2.push(1);
        vertices[1] = 2;
        ans2 = check(queue2, eov, edge, vertices);
    }
    outside2:

    if(ans1 || ans2){
        std::cout << "YES\n";

        for(int i = 0; i < m; i++){
            if(vertices[edge[i].first] == 1){
                std::cout << 1;
            }
            else{
                std::cout << 0;
            }
        }
        std::cout << "\n";

    }
    else{
        std::cout << "NO\n";
    }

    return 0;
}