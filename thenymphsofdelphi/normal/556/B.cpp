#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    x = 0 - a[0];
    for (int i = 0; i < n; i++){
        if (i & 1){
            a[i] -= x;
        }
        else{
            a[i] += x;
        }
    }
    for (int i = 0; i < n; i++){
        a[i] %= n;
        if (a[i] < 0){
            a[i] += n;
        }
        if (a[i] != i){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}