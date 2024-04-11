#include<bits/stdc++.h>
using namespace std;

int main(){
    long x, n;
    cin >> x >> n;
    while (n--){
        if (x % 10 == 0) x /= 10;
        else x--;
    }
    cout << x;
}