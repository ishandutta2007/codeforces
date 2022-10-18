#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long n, k, sep;
    cin >> n >> k;
    if (n % 2 == 0){
        sep = n / 2;
    }
    else{
        sep = n / 2 + 1;
    }
    if (k <= sep){
        cout << k * 2 - 1;
        return 0;
    }
    k -= sep;
    cout << k * 2;
}