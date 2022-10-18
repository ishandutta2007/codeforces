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
#include <string>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        a[i].first = i;
        a[i].second = temp;
    }

    std::vector<std::pair<int, int> > dec;
    std::vector<std::pair<int, int> > inc;

    bool ans = true;
    for(int i = 0; i < n; i++){
        if((inc.empty() || a[i].second > inc.back().second) && (dec.empty() || a[i].second < dec.back().second)){
            if(i == n - 1){
                inc.push_back(a[i]);
                continue;
            }
            if(a[i + 1].second > a[i].second){
                inc.push_back(a[i]);
            }
            else{
                dec.push_back(a[i]);
            }
        }
        else if(inc.empty() || a[i].second > inc.back().second){
            inc.push_back(a[i]);
        }
        else if(dec.empty() || a[i].second < dec.back().second){
            dec.push_back(a[i]);
        }
        else{
            ans = false;
            break;
        }
    }

    if(!ans){
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "Yes\n";

    bool b[n];
    for(auto it = dec.begin(); it != dec.end(); it++){
        b[it->first] = 1;
    }
    for(auto it = inc.begin(); it != inc.end(); it++){
        b[it->first] = 0;
    }

    for(int i = 0; i < n; i++){
        if(i != 0){
            std::cout << " ";
        }
        std::cout << b[i];
    }
    std::cout << "\n";

    return 0;
}