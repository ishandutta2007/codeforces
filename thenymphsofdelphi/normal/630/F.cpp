#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int n;
    cin >> n;
    int ans = 0;
    ans += n / 1 * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5;
    ans += n / 1 * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6;
    ans += n / 1 * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6 * (n - 6) / 7;
    cout << ans;
}