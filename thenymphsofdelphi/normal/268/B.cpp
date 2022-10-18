#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    cin >> n;
    long ans = n;
    for (i = 1; i < n; i++){
        ans += i * (n - i);
    }
    cout << ans;
}