#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int ans = n / 1 * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5;
    ans *= n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
    cout << ans;
}