#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, x, y, z, sum = 0;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    for (i = 0; i < n; i++){
        x = a[i] - '0';
        y = b[i] - '0';
        z = (x + 5) % 10;
        sum += abs(5 - abs(y - z));
    }
    cout << sum;
}