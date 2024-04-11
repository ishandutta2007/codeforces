#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], x, y;
    a[0] = 0;
    for (int i = 1; i < n; i++){
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    cin >> x >> y;
    x--;
    y--;
    cout << a[y] - a[x];
}