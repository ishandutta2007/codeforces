#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m = n / 3;
    if (n % 3 == 2){
        cout << 2 << ' ' << 1 << ' ' << n - 3;
        return 0;
    }
    cout << 1 << ' ' << 1 << ' ' << n - 2;
}