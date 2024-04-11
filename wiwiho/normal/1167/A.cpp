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

    int t;
    std::cin >> t;

    for(int testcase = 0; testcase < t; testcase++){

        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        bool ans = false;
        for(int i = 0; i < n - 10; i++){
            if(s[i] == '8'){
                ans = true;
            }
        }

        std::cout << (ans ? "YES" : "NO") << "\n";

    }
    
    return 0;
}