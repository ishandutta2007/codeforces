#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <random>
#include <unistd.h>

int n;
bool empty[2][100];

void read(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::string a, b;
    std::cin >> a >> b;
    n = a.size();
    for(int i = 0; i < a.size(); ++i){
        empty[0][i] = (a[i] == '0');
        empty[1][i] = (b[i] == '0');
    }
}

int answer(){
    int count = 0;
    int have = 0;
    for(int i = 0; i < n; ++i){
        if(have == 0){
            have += (int)empty[0][i] + (int)empty[1][i];
        }else if(have == 1){
            if(empty[0][i] && empty[1][i]){
                count++;
                have = 0;
            }else if(empty[0][i] || empty[1][i]){
                have = 1;
            }else{
                have = 0;
            }
        // have == 2
        }else{
            if(empty[0][i] || empty[1][i]){
                count++;
                have = (int)(empty[0][i] == empty[1][i]);
            }else{
                have = 0;
            }
        }
    }
    return count;
}


int main(){
    read();
    std::cout << answer();
    return 0;
}