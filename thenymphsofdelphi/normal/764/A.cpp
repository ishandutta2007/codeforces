#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a > b){
        swap(a, b);
    }
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int d = lcm(a, b);
    cout << c / d;
}