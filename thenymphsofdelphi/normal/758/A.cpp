#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, mx = -1, sum = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        sum += x;
        if (mx < x){
            mx = x;
        }
    }
    cout << mx * n - sum;
}