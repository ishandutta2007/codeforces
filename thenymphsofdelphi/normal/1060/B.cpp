#include<bits/stdc++.h>
using namespace std;
#define int long long

int dig(int n){
    int ans = 0;
    while (n > 0) {
        ans++;
        n /= 10;
    }

    return ans;
}

int sum(int n){
    int ans = 0;
    while (n > 0){
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

signed main(){
    int n, d, t = 0;
    cin >> n;
    d = dig(n);
    for (int i = 0; i < d - 1; i++){
        t = t * 10 + 9;
    }
    int rem = n - t;
    cout << sum(t) + sum(rem);
}