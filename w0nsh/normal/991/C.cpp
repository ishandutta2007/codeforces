#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

ll n;

void read(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
}

bool check(ll k){
    ll eaten = 0;
    ll num = n;
    while(num > 0){
        eaten += std::min(k, num);
        num -= std::min(k, num);
        num -= num/10;
    }
    return (eaten*2 >= n);
}

void answer(){
    if(n == 1){
        std::cout << "1\n";
        return;
    }
    ll left = 1;
    ll right = n;
    ll good = 0;
    while(left <= right){
        ll mid = (left + right) >> 1;
        if(!check(mid)){
            left = mid+1;
        }else{
            good = mid;
            right = mid-1;
        }
    }
    std::cout << good << "\n";
}

int main(){
    read();
    answer();
    return 0;
}