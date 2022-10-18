#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6){
        if (n % i == 0){
            return 0;
        }
    }
    for (int i = 7; i * i <= n; i += 6){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    cin >> n;
    for (int m = 1; m <= 1000; m++){
        if (!isprime(n * m + 1)){
            cout << m;
            return 0;
        }
    }
}