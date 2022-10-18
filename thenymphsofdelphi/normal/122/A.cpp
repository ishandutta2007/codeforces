#include<iostream>
using namespace std;

bool lucky(int n){
    while (n != 0){
        if (n % 10 != 4 && n % 10 != 7) return false;
        n /= 10;
    }
    return true;
}

bool almost_lucky(int n){
    if (lucky(n)) return true;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0 && (lucky(i) || lucky(n / i))) return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    if (almost_lucky(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}