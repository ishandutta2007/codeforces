#include<iostream>
#include<math.h>
//#include<string.h>
//#include<ctype.h>
using namespace std;

bool isprime(int n){
    if (n <= 1){
        return false;
    }
    if (n == 2 || n == 3 || n == 5){
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0){
        return false;
    }
    int sqrtn = sqrt(n);
    for (int i = 5; i < sqrtn; i += 6){
        if (n % i == 0){
            return false;
        }
    }
    for (int i = 7; i < sqrtn; i += 6){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, i;
    cin >> n;
    for (i = 2; i <= n / 2 + 1; i++){
        if (!isprime(i) && !isprime(n - i)){
            cout << i << " " << n - i;
            return 0;
        }
    }
}