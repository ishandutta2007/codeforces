#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, i, x, s = 0;
    cin >> n >> k;
    k = 5 - k;
    for (i = 0; i < n; i++){
        cin >> x;
        if (x <= k) s++;
    }
    cout << s / 3;
}