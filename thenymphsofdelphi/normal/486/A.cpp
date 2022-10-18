#include<iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long  ans = (n + 1) / 2;
    if (n % 2 == 1){
        ans = -ans;
    }
    cout << ans;
}