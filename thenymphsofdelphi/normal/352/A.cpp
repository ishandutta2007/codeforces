#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, a = 0, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x == 0){
            a++;
        }
        else{
            b++;
        }
    }
    b = (b / 9) * 9;
    if (a == 0){
        cout << -1;
        return 0;
    }
    if (b == 0){
        cout << 0;
        return 0;
    }
    for (int i = 0; i < b; i++){
        cout << "5";
    }
    for (int i = 0; i < a; i++){
        cout << "0";
    }
}