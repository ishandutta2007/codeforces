#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, d;
    cin >> n >> d;
    int a[n], ans = 2;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i++){
        int dif = a[i] - a[i - 1];
        if (dif == 2 * d){
            ans++;
        }
        else if (dif > 2 * d){
            ans += 2;
        }
    }
    cout << ans;
}