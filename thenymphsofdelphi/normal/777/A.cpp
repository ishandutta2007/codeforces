#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    n %= 6;
    while (n != 0){
        if (n % 2 == 0){
            if (x != 0){
                x = 3 - x;
            }
        }
        else{
            if (x != 2){
                x = 1 - x;
            }
        }
        n--;
    }
    cout << x;
}