#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (a > n || b > n || c > a || c > b){
        cout << -1;
        return 0;
    }
    int d = a - c, e = b - c;
    if (d + e + c >= n){
        cout << -1;
        return 0;
    }
    cout << n - d - e - c;
}