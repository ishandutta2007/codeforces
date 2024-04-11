#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        int x;
        std::cin >> x;
        sum += x;
    }
    std::cout << sum << "\n";
    return 0;
}