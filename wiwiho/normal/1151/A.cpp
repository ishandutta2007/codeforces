#include <iostream>
#include <iomanip>
#include <assert.h>
#include <math.h>
#include <string.h>
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

int distance(char a, char b){
    return std::min(std::abs((a - 'A') - (b - 'A')), 26 - std::abs((a - 'A') - (b - 'A')));
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;


    int ans = 100000000;
    for(int i = 0; i <= n - 4; i++){
        int operations = distance(s[i], 'A') + distance(s[i + 1], 'C') + distance(s[i + 2], 'T') + distance(s[i + 3], 'G');
        if(operations < ans){
            ans = operations;
        }
    }

    std::cout << ans << "\n";

    return 0;
}