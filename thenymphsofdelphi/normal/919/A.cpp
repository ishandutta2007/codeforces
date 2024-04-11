#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, a = 101, b = 1, x, y;
    cin >> n >> k;
    while (n--){
        cin >> x >> y;
        if (a * y > b * x){
            a = x;
            b = y;
        }
    }
    cout << fixed << setprecision(6) << a * k * 1.0 / b;
}