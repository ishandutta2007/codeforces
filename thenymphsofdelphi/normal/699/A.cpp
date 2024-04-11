#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, ans = 4e9;
    string s;
    cin >> n;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i++){
        if (s[i] == 'L' && s[i - 1] == 'R'){
            ans = min(ans, (a[i] - a[i - 1]) / 2);
        }
    }
    if (ans == 4e9){
        ans = -1;
    }
    cout << ans;
}