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

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::map<long double, int> map;
    int ans = 0;
    int all = 0;
    for(int i = 0; i < n; i++){
        int b;
        std::cin >> b;
        long double d = (long double)-b / (long double)a[i];
        if(a[i] == 0){
            if(b == 0){
                all++;
            }
            continue;
        }
        int amount = ++map[d];
        if(amount > ans){
            ans = amount;
        }
    }

    std::cout << (ans + all) << "\n";

    return 0;
}