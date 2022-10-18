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

    int a[3];
    std::cin >> a[0] >> a[1] >> a[2];
    
    int ans = 0;

    if(a[0] >= 3 && a[1] >= 2 && a[2] >= 2){
        int aa = a[0] / 3;
        int bb = a[1] / 2;
        int cc = a[2] / 2;
        int w = std::min(aa, std::min(bb, cc));
        ans += w * 7;
        a[0] = a[0] - w * 3;
        a[1] = a[1] - w * 2;
        a[2] = a[2] - w * 2;
    }

    int week[7] = {0, 0, 1, 2, 0, 2, 1};

    int tempans = 0;
    for(int i = 0; i < 7; i++){
        int temp = 0;
        int atemp[3] = {a[0], a[1], a[2]};
        for(int j = i; ; j++){
            j %= 7;
            if(atemp[week[j]] > 0){
                atemp[week[j]]--;
                temp++;
            }
            else{
                break;
            }
        }
        //std::cerr << i << " " << tempans << " " << ans << "\n";
        if(temp > tempans){
            tempans = temp;
        }
    }

    ans += tempans;
    std::cout << ans << "\n";

    return 0;
}