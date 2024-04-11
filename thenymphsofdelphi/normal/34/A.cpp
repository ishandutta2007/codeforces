#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, mn = 2000, x, y;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i++){
        if (abs(a[i] - a[i - 1]) < mn){
            mn = abs(a[i] - a[i - 1]);
            x = i;
            y = i - 1;
        }
    }
    if (abs(a[n - 1] - a[0]) < mn){
        x = n - 1;
        y = 0;
    }
    cout << x + 1 << ' ' << y + 1;
}