#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <functional>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int a[n];
    std::vector<int> odd;
    std::vector<int> even;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] % 2 == 0){
            even.push_back(a[i]);
        }
        else{
            odd.push_back(a[i]);
        }
    }

    std::sort(odd.begin(), odd.end(), std::greater<int>());
    std::sort(even.begin(), even.end(), std::greater<int>());

    auto oddIt = odd.begin();
    auto evenIt = even.begin();

    if(odd.size() >= even.size()){
        while(true){
            if(oddIt != odd.end()){
                oddIt++;
            }
            else{
                break;
            }
            if(evenIt != even.end()){
                evenIt++;
            }
            else{
                break;
            }
        }
    }
    else{
        while(true){
            if(evenIt != even.end()){
                evenIt++;
            }
            else{
                break;
            }
            if(oddIt != odd.end()){
                oddIt++;
            }
            else{
                break;
            }
        }
    }

    int ans = 0;
    for(; evenIt != even.end(); evenIt++){
        ans += *evenIt;
    }
    for(; oddIt != odd.end(); oddIt++){
        ans += *oddIt;
    }

    std::cout << ans << "\n";

    return 0;
}