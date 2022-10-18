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

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, r;
    std::cin >> n >> m >> r;

    int smin = 10000000;
    int bmax = 0;
    for(int i = 0; i < n; i++){
        int s;
        std::cin >> s;
        if(s < smin){
            smin = s;
        }
    }
    for(int i = 0; i < m; i++){
        int b;
        std::cin >> b;
        if(b > bmax){
            bmax = b;
        }
    }

    int ans = r;
    if(bmax > smin){

        int amount = r / smin;
        r %= smin;
        r += amount * bmax;
        ans = r;

    }

    std::cout << r << "\n";

    return 0;
}