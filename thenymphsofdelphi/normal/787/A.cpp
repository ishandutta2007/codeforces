#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, t;
    cin >> a >> b;
    cin >> c >> d;
    if (b == d){
        cout << b;
        return 0;
    }
    for (int i = 0; i <= 100; i++){
        t = a * i + b - d;
        if (t % c == 0 && t >= 0){
            cout << a * i + b;
            return 0;
        }
    }
    cout << -1;
}