#include<bits/stdc++.h>
using namespace std;

bool is_prime(long long n){
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= sqrt(n); i += 6){
        if (n % i == 0) return false;
    }
    for (int i = 7; i <= sqrt(n); i += 6){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    long long x, y;
    cin >> n;
    while (n--){
        cin >> x;
        y = sqrt(x);
        if (y * y == x && is_prime(y)) cout << "YES\n";
        else cout << "NO\n";
    }
}