#include<iostream>
using namespace std;

int gcd(int a, int b){
    while (b){
        b ^= a ^= b ^= a %= b;
    }
    return a;
}

int main(){
    int a, b, n, d;
    cin >> a >> b >> n;
    bool ck = true;
    while (n){
        if (ck){
            ck = false;
            d = gcd(a, n);
            n -= d;
        }
        else{
            ck = true;
            d = gcd(b, n);
            n -= d;
        }
    }
    cout << ck;
}