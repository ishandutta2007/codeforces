#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <functional>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::vector<int> inc;
    std::vector<int> dec;

    bool ans = true;

    for(auto it = a.begin(); it != a.end(); it++){

        if(!inc.empty() && inc.back() == *it){
            if(dec.empty() || dec.back() != *it){
                dec.push_back(*it);
            }
            else{
                ans = false;
                break;
            }
        }
        else{
            inc.push_back(*it);
        }

    }

    std::cout << (ans ? "YES" : "NO") << "\n";

    if(!ans){
        return 0;
    }

    std::cout << inc.size() << "\n";
    for(int i = 0; i < inc.size(); i++){
        if(i != 0){
            std::cout << " ";
        }
        std::cout << inc[i];
    }
    std::cout << "\n";

    std::cout << dec.size() << "\n";
    for(int i = dec.size() - 1; i >= 0; i--){
        if(i != dec.size() - 1){
            std::cout << " ";
        }
        std::cout << dec[i];
    }
    std::cout << "\n";

    return 0;
}