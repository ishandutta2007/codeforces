#include<bits/stdc++.h>
using namespace std;

int main(){
    int mx = 0, n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--){
        if (a[i] > mx){
            b[i] = 0;
            mx = a[i];
            continue;
        }
        b[i] = mx - a[i] + 1;
    }
    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
}