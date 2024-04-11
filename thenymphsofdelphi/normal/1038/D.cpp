#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500005];

signed main(){
    int n, ans = 0, mn = 1e9 + 5;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans += abs(a[i]);
        mn = min(mn, abs(a[i]));
    }
    if (n == 1){
        cout << a[0];
        return 0;
    }
    if (ans == 0){
        cout << 0;
        return 0;
    }
    int ck = 0;
    for (int i = 1; i < n; i++){
        if (abs(a[i] + a[i - 1]) != abs(a[i]) + abs(a[i - 1])){
            ck = 1;
            break;
        }
    }
    if (ck){
        cout << ans;
        return 0;
    }
    cout << ans - 2 * mn;
}