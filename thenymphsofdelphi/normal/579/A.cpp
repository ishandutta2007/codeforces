#include<bits/stdc++.h>
using namespace std;

int main(){
    long x;
    cin >> x; 
    long ans = 1;
    while (x != 1){
        if (x % 2 == 1) ans++;
        x /= 2;
    }
    cout << ans;
}