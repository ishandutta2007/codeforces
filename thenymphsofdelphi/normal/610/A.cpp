#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    if (n % 2 != 0){
        cout << 0;
        return 0;
    }
    n /= 2;
    cout << (n - 1) / 2;
}