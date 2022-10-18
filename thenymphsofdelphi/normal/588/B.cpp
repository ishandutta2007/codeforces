#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int ans = 1;
    int x = n;
    for (int i = 2; i * i <= n; i++){
        if (x % i == 0){
            ans *= i;
            while (x % i == 0){
                x /= i;
            }
        }
    }
    if (x > 1){
        ans *= x;
    }
    cout << ans;
}