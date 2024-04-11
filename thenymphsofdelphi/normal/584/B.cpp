#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

signed main(){
    int n, a, b;
    cin >> n;
    a = 1;
    b = 1;
    for (int i = 0; i < n; i++){
        a = a * 27 % mod;
        b = b * 7 % mod;
    }
    cout << (a + mod - b) % mod;
}