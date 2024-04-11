#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    bool isLeaf[n + 1];
    for(int i = 1; i <= n; i++){
        isLeaf[i] = true;
    }

    std::vector<std::vector<int> > children(n + 1);

    for(int i = 1; i <= n - 1; i++){
        int pi;
        std::cin >> pi;
        children[pi].push_back(i + 1);
        isLeaf[pi] = false;
    }

    bool ans = true;
    for(int i = 1; i <= n; i++){
        if(isLeaf[i]){
            continue;
        }
        int leaf = 0;
        for(auto it = children[i].begin(); it != children[i].end(); it++){
            if(isLeaf[*it]){
                leaf++;
            }
        }
        if(leaf < 3){
            ans = false;
            break;
        }
    }

    std::cout << (ans ? "Yes\n" : "No\n");

    return 0;
}