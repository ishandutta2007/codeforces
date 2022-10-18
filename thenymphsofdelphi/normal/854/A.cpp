#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}

int main(){
    int n;
    cin >> n;
    for (int i = (n - 1) / 2; i > 0; i--){
        if (gcd(i, n - i) == 1){
            cout << i << " " << n - i;
            return 0;
        }
    }
}