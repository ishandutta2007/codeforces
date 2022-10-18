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

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n,t;
    std::cin >> n >> t;

    int ans = 0;
    int anstime = 1000000000;
    for(int i = 1; i <= n; i++){
        int s, d;
        std::cin >> s >> d;
        if(s < t){
            s = ceil((double)(t - s) / (double)d) * d + s;
        }
        //std::cerr << s << "\n";
        if(s - t < anstime){
            anstime = s - t;
            ans = i;
        }
    }

    std::cout << ans << "\n";

    return 0;
}