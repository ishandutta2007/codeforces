#include <iostream>
#include <assert.h>
#include <algorithm>
#include <map>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int a[n];
    
    int max = 0;
    int maxLast = -1;

    std::map<int, int> numberAmount;

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        
        numberAmount[a[i]]++;
        if(numberAmount[a[i]] > max){
            max = numberAmount[a[i]];
            maxLast = i;
        }
    }

    std::cout << (n - max) << "\n";

    for(int i = maxLast; i < n - 1; i++){
        if(a[i + 1] < a[i]){
            a[i + 1] = a[i];
            std::cout << "1 " << (i + 1 + 1) << " " << (i + 1) << "\n";
        }
        else if(a[i + 1] > a[i]){
            a[i + 1] = a[i];
            std::cout << "2 " << (i + 1 + 1) << " " << (i + 1) << "\n";
        }
    }

    for(int i = maxLast; i > 0; i--){
        if(a[i - 1] < a[i]){
            a[i - 1] = a[i];
            std::cout << "1 " << (i - 1 + 1) << " " << (i + 1) << "\n";
        }
        else if(a[i - 1] > a[i]){
            a[i - 1] = a[i];
            std::cout << "2 " << (i - 1 + 1) << " " << (i + 1) << "\n";
        }
    }

    return 0;
}