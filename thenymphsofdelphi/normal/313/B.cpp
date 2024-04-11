#include<bits/stdc++.h>
using namespace std;

int dp[100010];

int main(){
    string a;
    cin >> a;
    int n = a.length(), q, l, r;
    dp[0] = 0;
    for (int i = 1; i < n; i++){
        dp[i] = dp[i-1];
        if (a[i] == a[i-1]) dp[i]++;
    }
    cin >> q;
    while (q--){
        cin >> l >> r;
        cout << dp[r-1] - dp[l-1] << endl;
    }
}