#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

const int INF = 1000000000;

ll n;
std::vector<int> num;

int dostan(std::vector<int> &vec, int pos, int od_konca){
    if(pos == vec.size()-od_konca) return 0;
    // if(od_konca == 2 && pos == vec.size()-1){
    //     std::swap(vec[vec.size()-1], vec[vec.size()-2]);
    //     return 1;
    // }
    int ret = 0;
    if(pos != 0 || vec[1] != 0){
        for(int i = pos; i < vec.size() - od_konca; ++i){
            std::swap(vec[i], vec[i+1]);
            ret++;
        }
    }else{
        int first_good = -1;
        for(int i = 0; i < vec.size(); ++i){
            if(i != pos && vec[i] != 0){
                first_good = i;
                break;
            }
        }
        for(int i = first_good; i >= 1; --i){
            std::swap(vec[i], vec[i-1]);
            ret++;
        }
        pos = 1;
        for(int i = pos; i < vec.size() - od_konca; ++i){
            std::swap(vec[i], vec[i+1]);
            ret++;
        }
    }
    return ret;
}

int check_00(){
    int ret = 0;
    std::vector<int> numcpy = num;
    int last = -1;
    int before = -1;
    for(int i = num.size()-1; i >= 0; --i){
        if(num[i] != 0) continue;
        if(last == -1) last = i;
        else{
            before = i;
            break;
        }
    }
    if(before == -1) return INF;
    ret += dostan(numcpy, last, 1);
    ret += dostan(numcpy, before, 2);
    return ret;
}

int check_25(){
    int ret = 0;
    std::vector<int> numcpy = num;
    int two = -1;
    int five = -1;
    int zero_count = 0;
    for(int i = num.size()-1; i >= 0; --i){
        if(num[i] == 2 && two == -1) two = i;
        if(num[i] == 5 && five == -1) five = i;
        if(num[i] == 0) zero_count++;
    }
    if(zero_count == num.size()-2 && num.size() != 2) return INF;
    if(two == -1 || five == -1) return INF;
    int add = 0;
    if(five == num.size()-2){
        std::swap(numcpy[num.size()-1], numcpy[num.size()-2]);
        five++;
        add++;
        if(numcpy[num.size()-2] == 2) return 1;
    }
    if(two < five){
        ret += dostan(numcpy, five, 1);
        ret += dostan(numcpy, two, 2);
    }else{
        ret += dostan(numcpy, two, 1);
        ret += dostan(numcpy, five, 1);
    }
    return ret + add;
}

int check_50(){
    int ret = 0;
    std::vector<int> numcpy = num;
    int five = -1;
    int zero = -1;
    int zero_count = 0;
    for(int i = num.size()-1; i >= 0; --i){
        if(num[i] == 0 && zero == -1) zero = i;
        if(num[i] == 5 && five == -1) five = i;
        if(num[i] == 0) zero_count++;
    }
    if(zero_count == num.size()-1 && num.size() != 2) return INF;
    if(zero == -1 || five == -1) return INF;
    int add = 0;
    if(zero == num.size()-2){
        std::swap(numcpy[num.size()-1], numcpy[num.size()-2]);
        zero++;
        add++;
        if(numcpy[num.size()-2] == 5) return 1;
    }
    if(zero < five){
        ret += dostan(numcpy, five, 1);
        ret += dostan(numcpy, zero, 1);
    }else{
        ret += dostan(numcpy, zero, 1);
        ret += dostan(numcpy, five, 2);
    }
    return ret + add;
}

int check_75(){
    int ret = 0;
    std::vector<int> numcpy = num;
    int seven = -1;
    int five = -1;
    int zero_count = 0;
    for(int i = num.size()-1; i >= 0; --i){
        if(num[i] == 7 && seven == -1) seven = i;
        if(num[i] == 5 && five == -1) five = i;
        if(num[i] == 0) zero_count++;
    }
    if(zero_count == num.size()-2 && num.size() != 2) return INF; 
    if(seven == -1 || five == -1) return INF;
    int add = 0;
    if(five == num.size()-2){
        std::swap(numcpy[num.size()-1], numcpy[num.size()-2]);
        five++;
        add++;
        if(numcpy[num.size()-2] == 7) return 1;
    }
    if(seven < five){
        ret += dostan(numcpy, five, 1);
        ret += dostan(numcpy, seven, 2);
    }else{
        ret += dostan(numcpy, seven, 1);
        ret += dostan(numcpy, five, 1);
    }
    return ret + add;
}

void answer(){
    if(num.size() < 2){
        std::cout << "-1" << "\n";
        return;
    }
    // std::cout << check_00() << " " << check_25() <<  " " << check_50() << " " << check_75() << std::endl;
    int ans = std::min(std::min(check_00(), check_25()), std::min(check_50(), check_75()));
    std::cout << (ans == INF ? -1 : ans) << "\n";
}

void read(){
    std::cin >> n;
    while(n > 0){
        num.push_back(n % 10);
        n /= 10;
    }
    std::reverse(num.begin(), num.end());
}

int main(){
    read();
    answer();
    return 0;
}