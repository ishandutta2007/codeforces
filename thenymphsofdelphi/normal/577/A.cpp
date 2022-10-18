#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long x, ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        int j = x / i;
        if (i * j == x && j <= n) ans++;
    }
    cout << ans;
}