#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, k, ans = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] += k - 1;
        ans += a[i] / k;
    }
    cout << (ans + 1) / 2;
}