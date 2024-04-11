#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, t = 0, ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans += abs(t - a[i]);
        t = a[i];
    }
    cout << ans;
}