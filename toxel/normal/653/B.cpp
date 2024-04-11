#include<bits/stdc++.h>

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    std::map <std::string, std::vector <std::string>> map;
    for (int i = 0; i < q; ++ i){
        std::string a, b;
        std::cin >> a >> b;
        map[b].push_back(a);
    }
    std::queue <std::string> queue;
    std::set <std::string> set;
    queue.push(std::string() + 'a');
    set.insert(std::string() + 'a');
    while (!queue.empty() && queue.front().size() < n){
        std::string str = queue.front();
        queue.pop();
        for (auto u : map[str.substr(0, 1)]){
            std::string nstr = u + str.substr(1, str.size() - 1);
            if (!set.count(nstr)){
                queue.push(nstr);
            }
        }
    }
    printf("%d\n", (int) queue.size());
    return 0;
}