#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    int a[n + 2], b[n + 2], c[n + 2], mx = -1;
    b[0] = 0;
    c[n + 1] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
        b[i] %= p;
    }
    for (int i = n; i >= 1; i--){
        c[i] = c[i + 1] + a[i];
        c[i] %= p;
    }
    for (int i = 1; i < n; i++){
        mx = max(mx, b[i] + c[i + 1]);
    }
    cout << mx;
}