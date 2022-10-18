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

    int n, b, a;
    std::cin >> n >> b >> a;

    int s[n + 1];
    for(int i = 1; i <= n; i++){
        std::cin >> s[i];
    }

    int battery = b;
    int accu = a;

    int i = 1;
    for(; i <= n; i++){
        if(s[i]){
            if(accu == a){
                accu--;
                continue;
            }
            else if(battery > 0 && accu < a){
                accu++;
                battery--;
                continue;
            }
            else if(accu > 0){
                accu--;
                continue;
            }
            else{
                i -= 1;
                break;
            }
        }
        else{
            if(accu > 0){
                accu--;
                continue;
            }
            else if(battery > 0){
                battery--;
                continue;
            }
            else{
                i -= 1;
                break;
            }
        }
    }

    if(i > n){
        i = n;
    }

    std::cout << i << "\n";

    return 0;
}