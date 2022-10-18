#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <typeinfo>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::stack<int>> left(27);
    std::vector<std::stack<int>> right(27);

    std::string ls;
    std::cin >> ls;
    for(int i = 0; i < n; i++){
        if(ls[i] == '?'){
            left[26].push(i + 1);
        }
        else{
            left[ls[i] - 'a'].push(i + 1);
        }
    }

    std::string rs;
    std::cin >> rs;
    for(int i = 0; i < n; i++){
        if(rs[i] == '?'){
            right[26].push(i + 1);
        }
        else{
            right[rs[i] - 'a'].push(i + 1);
        }
    }

    std::vector<std::pair<int, int>> ans;

    for(int i = 0; i < 26; i++){

        while(!left[i].empty()){
            if(!right[i].empty()){
                ans.push_back(std::make_pair(left[i].top(), right[i].top()));
                left[i].pop();
                right[i].pop();
            }
            else if(!right[26].empty()){
                ans.push_back(std::make_pair(left[i].top(), right[26].top()));
                left[i].pop();
                right[26].pop();
            }
            else{
                break;
            }
        }

        while(!right[i].empty()){
            if(!left[26].empty()){
                ans.push_back(std::make_pair(left[26].top(), right[i].top()));
                left[26].pop();
                right[i].pop();
            }
            else{
                break;
            }
        }

    }

    while(!left[26].empty() && !right[26].empty()){
        ans.push_back(std::make_pair(left[26].top(), right[26].top()));
        left[26].pop();
        right[26].pop();
    }

    std::cout << ans.size() << "\n";
    for(std::pair<int, int> p : ans){
        std::cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}