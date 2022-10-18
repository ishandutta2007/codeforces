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
#include <math.h>
#include <string.h>
#include <iomanip>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::map<int, int> a;

    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        a[temp]++;
    }
    a[-1] = 1;

    int ans = 0;

    for(auto it = ++a.begin(); it != a.end(); it++){
        int number = it->first;
        int temp = 0;
        for(auto it2 = it; it2 != a.begin() && it->first - it2->first <= 5; it2--){
            temp += it2->second;
        }
        if(temp > ans){
            ans = temp;
        }
    }

    std::cout << ans << "\n";

    return 0;
}