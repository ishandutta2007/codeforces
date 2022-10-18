#include<bits/stdc++.h>
using namespace std;
#define int long long

bool has8(int n){
    while (n != 0){
        if (n % 10 == 8 || n % 10 == -8){
            return 1;
        }
        n /= 10;
    }
    return 0;
}

signed main(){
    int n, ans = 0;
    cin >> n;
    do{
        ans++;
        n++;
    } while (!has8(n));
    cout << ans;
}