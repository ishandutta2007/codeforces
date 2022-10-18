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

    int n, k;
    std::cin >> n >> k;

    int amount[k + 1];
    memset(amount, 0, (k + 1) * sizeof(int));

    int ans = 0;

    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        temp %= k;
        if(amount[k - temp]){
            amount[k - temp]--;
            ans++;
        }
        else{
            if(temp == 0){
                amount[k]++;
            }
            else{
                amount[temp]++;
            }
        }
    }

    std::cout << (ans * 2) << "\n";

    return 0;
}