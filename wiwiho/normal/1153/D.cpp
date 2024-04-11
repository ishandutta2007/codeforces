#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

//#define TEST

int leaf = 0;

int dfs(int v, int n, int* minmax, std::vector<std::vector<int> > &child){

    if(child[v].size() == 0){
        leaf++;
        return 1;
    }

    if(minmax[v]){ //max
        int min = 10000000;
        for(auto it = child[v].begin(); it != child[v].end(); it++){
            min = std::min(min, dfs(*it, n, minmax, child));
        }
        return min;
    }
    else{ //min
        int sum = 0;
        for(auto it = child[v].begin(); it != child[v].end(); it++){
            sum += dfs(*it, n, minmax, child);
        }
        return sum;
    }

}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    int minmax[n];
    for(int i = 0; i < n; i++){
        std::cin >> minmax[i];
    }

    std::vector<std::vector<int> > child(n);
    for(int i = 1; i < n; i++){
        int parent;
        std::cin >> parent;
        child[parent - 1].push_back(i);
    }

    int ans = dfs(0, n, minmax, child);
    std::cout << (leaf - ans + 1) << "\n";

    return 0;
}