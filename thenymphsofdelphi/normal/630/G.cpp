#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int ans = (n + 4) / 1 * (n + 3) / 2 * (n + 2) / 3 * (n + 1) / 4 * n / 5;
    ans *= (n + 2) / 1 * (n + 1) / 2 * n / 3;
    cout << ans;
}