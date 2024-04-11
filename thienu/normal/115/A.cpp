#define NOMINMAX

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>


using namespace std;

int dfs(int node, map<int, set<int>> &children, set<int> &roots){
    // printf("dfs %d\n", node);
    int maxi = 1;
    for(auto &child : children[node]){
        // printf("child %d of node %d\n", child, node);
        maxi = max(dfs(child, children, roots)+1, maxi);
    }
    return maxi;
}

int main(){
    map<int, set<int>> children;
    set<int> roots;
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        if(x == -1){
            // printf("inserted root %d\n", i);
            roots.insert(i);
        }
        else{
            // printf("inserted child %d to %d\n", i, x);
            children[x].insert(i);
        }
    }
    int maxi = 0;
    for(auto &r : roots){
        maxi = max(maxi, dfs(r, children, roots));
    }
    printf("%d\n", maxi);
    return 0;
}