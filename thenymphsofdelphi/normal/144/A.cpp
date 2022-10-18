#include<iostream>
using namespace std;

int main(){
    int n, x = 101, y = 0, xi, yi, i, t, ans;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> t;
        if (t <= x){
            xi = i;
            x = t;
        }
        if (t > y){
            yi = i;
            y = t;
        }
    }
    ans = (n - 1 - xi) + yi;
    if (ans >= n) ans--;
    cout << ans;
}