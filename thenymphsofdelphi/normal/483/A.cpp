#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b){
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}

signed main(){
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r - 2; i++){
        for (int j = i + 1; j <= r - 1; j++){
            for (int k = j + 1; k <= r; k++){
                if (gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) != 1){
                    cout << i << ' ' << j << ' ' << k;
                    return 0;
                }
            }
        }
    }
    cout << -1;
}