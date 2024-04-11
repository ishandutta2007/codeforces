#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <functional>

class Node{
    public:
    void set(int ap, int ac){
        p = ap;
        c = ac;
    }
    int p;
    int c;
};

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    Node tree[n + 1];
    bool notRespect[n + 1];

    for(int i = 1; i <= n; i++){
        int p,c;
        std::cin >> p >> c;
        tree[i].set(p, c);
        notRespect[i] = c;
    }

    for(int i = 1; i <= n; i++){
        if(tree[i].c || tree[i].p == -1){
            continue;
        }
        notRespect[tree[i].p] = false;
    }

    int amount = 0;
    for(int i = 1; i <= n; i++){
        if(notRespect[i]){
            if(amount != 0){
                std::cout << " ";
            }
            amount++;
            std::cout << i;
        }
    }
    if(amount == 0){
        std::cout << -1;
    }
    std::cout << "\n";

    return 0;
}