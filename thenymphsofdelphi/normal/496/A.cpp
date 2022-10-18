#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n - 1];
    int mx = -1, mx2 = 1000000;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++){
        b[i] = a[i + 1] - a[i];
        mx = max(mx, b[i]);
    }
    for (int i = 0; i < n - 2; i++){
        mx2 = min(mx2, max(b[i + 1] + b[i], mx));
    }
    cout << mx2;
}