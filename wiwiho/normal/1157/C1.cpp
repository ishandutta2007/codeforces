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

    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int front = 0;
    int back = n - 1;

    std::string result = "";
    int ans = 0;
    int last = 0;
    while(front <= back){
        if(a[front] < a[back] && a[front] > last){
            result.append("L");
            last = a[front];
            front++;
            ans++;
        }
        else if(a[back] > last){
            result.append("R");
            last = a[back];
            back--;
            ans++;
        }
        else if(a[front] > last){
            result.append("L");
            last = a[front];
            front++;
            ans++;
        }
        else{
            break;
        }
    }

    std::cout << ans << "\n";
    std::cout << result << "\n";

    return 0;
}