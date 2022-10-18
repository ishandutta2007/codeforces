#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 0){
        cout << 1;
        return 0;
    }
    n %= 4;
    if (n == 0){
        cout << 6;
        return 0;
    }
    if (n == 1){
        cout << 8;
        return 0;
    }
    if (n == 2){
        cout << 4;
        return 0;
    }
    cout << 2;
}