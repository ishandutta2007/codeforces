#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum = 0, n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        sum += x;
    }
    int ans = 0;
    sum++;
    if (sum % (n + 1) == 1){
        ans++;
    }
    sum++;
    if (sum % (n + 1) == 1){
        ans++;
    }
    sum++;
    if (sum % (n + 1) == 1){
        ans++;
    }
    sum++;
    if (sum % (n + 1) == 1){
        ans++;
    }
    sum++;
    if (sum % (n + 1) == 1){
        ans++;
    }
    cout << 5 - ans;
}