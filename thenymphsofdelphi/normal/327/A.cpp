#include<bits/stdc++.h>
using namespace std;

int a[200], n;

int main(){
    int x, mxn, mx = 0, y;
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    a[n + 1] = a[n];
    mxn = a[n];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            y = mxn + (i - j + 1) - 2 * (a[i] - a[j - 1]);
            mx = max(mx, y);
        }
    }
    cout << mx;
}