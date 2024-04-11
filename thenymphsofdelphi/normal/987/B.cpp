#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    int a, b;
    cin >> a >> b;
    if (a == b){
        cout << '=';
        return 0;
    }
    if (a == 1){
        cout << '<';
        return 0;
    }
    if (b == 1){
        cout << '>';
        return 0;
    }
    if (a + b == 6){
        cout << '=';
        return 0;
    }
    if (a == 3){
        cout << '>';
        return 0;
    }
    if (b == 3){
        cout << '<';
        return 0;
    }
    if (a < b){
        cout << '>';
        return 0;
    }
    if (a > b){
        cout << '<';
        return 0;
    }
}