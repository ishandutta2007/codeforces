#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, x, mn = 1e6;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (k % x == 0){
            mn = min(mn, k / x);
        }
    }
    cout << mn;
}